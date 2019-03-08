from flask import render_template
from app import app
from .forms import NewUserForm, LoginForm, SelectDates, ExtendDate, PasswordChangeForm

# all imports for sending emails
import smtplib
from email.mime.multipart import MIMEMultipart
from email.mime.text import MIMEText
from email.mime.base import MIMEBase
from email.mime.image import MIMEImage
from email import encoders

# all imports for QR Code Generation
import pyqrcode


@app.route('/')
def home():
    return render_template("home.html")

@app.route('/about')
def about():
    return render_template("about.html") # redirect to the about page

@app.route('/meetOurStaff')
def meetOurStaff():
    return render_template("meetOurStaff.html") # redirect to the about page

@app.route('/browse')
def browse():
    form = SelectDates();
    return render_template("browse.html", form=form) # redirect to the bike search page

@app.route('/bikePage')
def bikePage():
    form = SelectDates();
    return render_template("bikePage.html", form=form) # redirect to the bike search page

@app.route('/account')
def account():
    form = ExtendDate();
    return render_template("account.html", form=form) # redirect to the account page

@app.route('/changePassword')
def changePassword():
    form = PasswordChangeForm();
    return render_template("changePassword.html", form=form) # redirect to the change password page

@app.route('/sign_up', methods=['GET', 'POST'])
def sign_up():
	form = NewUserForm()
	return render_template("sign_up.html", form=form)


@app.route('/login', methods=['GET', 'POST'])
def login():
	form = LoginForm()
	return render_template("login.html", form=form)


def makeBikeRentalsTable(databaseOutput):
    output = ""
    for bike in databaseOutput:
        output +=  """   <tr>
  <td>""" + bike[0] +  """</span></td>
  <td>""" + bike[1] + """</span></td>
  <td>""" + bike[2] + """</span></td>
  <td>""" + bike[3] + """</span></td>
  <td>""" + bike[4] + """</span></td>
</tr>
"""
    return output

def makeCheckoutTable(databaseOutput):
    output = ""
    titles = ["UserName","Date","Time","User ID","Total Price"]
    for i in range(len(titles)):
        output += """  <tr>
    <th>""" + titles[i] + """</th>
    <td>""" + databaseOutput[i] + """</td>
  </tr> """

    return output



@app.route('/qr', methods=['GET', 'POST'])
def qr():

    # generating the QR code
    url = pyqrcode.create('https://ksassets.timeincuk.net/wp/uploads/sites/55/2016/07/2015_PeepShow_Mark2_Press_111115-920x610.jpg')
    url.png('app/qrCode.png', scale=2) # nice and big


    # we take this dummy database output for use in the emails
    dummyDatabaseOutput = [["Carrera Kraken","4372812","28/02/19","02/03/19","35.6"],
                          ["Boardman MTB 8.8","2841849","05/04/19","08/04/19","108.2"],
                          ["Apollo Storm","7394836","08/04/19","15/04/19","57.8"],
                          ["Apollo Storm","7394836","08/04/19","15/04/19","57.8"]]

    dummyRecieptOutput = ["Jonathan Alderson", "27/02/19","15:36:23","5437289","76.8"]


    # setting up email things
    sendingAddress = "16.cycles.recipt@gmail.com"
    sendingPassword = "phatgitproject"
    receivingAddress = "jonathancharlesalderson@gmail.com"

    msg = MIMEMultipart()

    msg['From'] = "16 Cycles Rentals"
    msg['To'] = receivingAddress
    msg['Subject'] = "Your Reciept From Today"



    # actual body of the email
    html = """\
        <html>
        <head>
          <title>16 Cycles</title>
        </head>
        <body aria-readonly="false" style="cursor: auto; font-family: arial,helvetica,sans-serif;  background-image:url(cid:image1); background-repeat: no-repeat">
        <body>
        <br/><br/><br/>
        <h1>Thank you for renting with us today</h1>
        Please find attached below your recipt
        <br/><br/><br/><br/><br/>
        <table  align="left" border="0" cellpadding="5" cellspacing="1" style="width:800px, text-align:center, cellpadding:100px" >
        """ + makeCheckoutTable(dummyRecieptOutput) + """
        </table>
        <br/><br/><br/><br/><br/><br/><br/><br/><br/><br/>
        <br/><br/><br/><br/><br/><br/><br/><br/><br/><br/>
        <table align="left" border="0" cellpadding="10" cellspacing="1" style="width:800px, text-align:center, cellpadding:100px" >
          <thead>
            <tr>
              <th scope="col">Bike</span></th>
              <th scope="col">Bike ID</span></th>
              <th scope="col">Start Date</span></th>
              <th scope="col">End Date</span></th>
              <th scope="col">Price</span></th>
            </tr>
          </thead>
          <tbody> """ + makeBikeRentalsTable(dummyDatabaseOutput) + """

          </tbody>
        </table>
        <img src="cid:image2 alt="Your QR Code">
        <br/><br/><br/>

        </body>
        </html>
    """

    # Add the HTML
    emailBody = MIMEText(html, 'html')



    # adds the qr image
    fp = open('app/qrCode.png','rb')
    msgImage = MIMEImage(fp.read())
    fp.close()
    msgImage.add_header('Content-ID','<image2>')
    msg.attach(msgImage)

    # adds the background image
    fp = open('app/emailBackground.png','rb')
    msgImage = MIMEImage(fp.read())
    fp.close()
    msgImage.add_header('Content-ID','<image1>')
    msg.attach(msgImage)




    msg.attach(emailBody)

    # setup email sending
    server = smtplib.SMTP('smtp.gmail.com', 587)
    server.starttls()
    server.login(sendingAddress, sendingPassword)
    text = msg.as_string()

    # commented out to stop spamming
    server.sendmail(sendingAddress,receivingAddress , msg.as_string())
    server.quit()

    # display webpage saying it worked
    return render_template("qr.html")
