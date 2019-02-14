from flask import render_template
from app import app
from .forms import NewUserForm, LoginForm, SelectDates

# all imports for sending emails
import smtplib
from email.MIMEMultipart import MIMEMultipart
from email.MIMEText import MIMEText
from email.MIMEBase import MIMEBase
from email.MIMEImage import MIMEImage
from email import encoders

# all imports for QR Code Generation
import pyqrcode


@app.route('/')
def home():
    return render_template("home.html")

@app.route('/about')
def about():
    return render_template("about.html") # redirect to the about page

@app.route('/browse')
def browse():
    form = SelectDates();
    return render_template("browse.html", form=form) # redirect to the bike search page

@app.route('/account')
def account():
    return render_template("account.html") # redirect to the account page

@app.route('/sign_up', methods=['GET', 'POST'])
def sign_up():
	form = NewUserForm()
	return render_template("sign_up.html", form=form)


@app.route('/login', methods=['GET', 'POST'])
def login():
	form = LoginForm()
	return render_template("login.html", form=form)

@app.route('/qr', methods=['GET', 'POST'])
def qr():

    # generating the QR code
    url = pyqrcode.create('https://ksassets.timeincuk.net/wp/uploads/sites/55/2016/07/2015_PeepShow_Mark2_Press_111115-920x610.jpg')
    url.png('app/qrCode.png', scale=6) # nice and big




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
        <body aria-readonly="false" style="cursor: auto; font-family: arial,helvetica,sans-serif; background-image:url(cid:image2); background-repeat: no-repeat">
        <br/><br/><br/>
        <h1>Thank you for renting with us today</h1>
        Please find attached below your recipt
        <br/><br/><br/><br/><br/>
        <table  align="left" border="0" cellpadding="5" cellspacing="1" style="width:800px, text-align:center, cellpadding:100px" >
          <tr>
            <td>UserName</td>
            <td>jonathanAlderson</td>
          </tr>
          <tr>
            <td>Date</td>
            <td>15/02/19</td>
          </tr>
          <tr>
            <td>Time</td>
            <td>22:24.47</td>
          </tr>
          <tr>
            <td>ID</td>
            <td>5743894532</td>
          </tr>
          <tr>
            <td>Price</td>
            <td>54.4</td>
          </tr>
        </table>

        <br/><br/><br/><br/><br/><br/>
        <br/><br/><br/><br/><br/><br/>
        <br/><br/><br/><br/><br/><br/>

        <table align="left" border="0" cellpadding="10" cellspacing="1" style="width:800px, text-align:center, cellpadding:100px" >
          <thead>
            <tr>
              <th scope="col">Bike</span></th>
              <th scope="col">Start Date</span></th>
              <th scope="col">End Date</span></th>
              <th scope="col">Price</span></th>
            </tr>
          </thead>
          <tbody>
            <tr>
              <td>Carrera&nbsp;kraken</span></td>
              <td>15/02/19</span></td>
              <td>21/02/19</span></td>
              <td>37.6</span></td>
            </tr>
            <tr>
              <td>Boardman MTB 8.9</span></td>
              <td>25/02/19</span></td>
              <td>27/02/19</span></td>
              <td>16.8</span></td>
            </tr>
            <tr>
              <td>&nbsp;</td>
              <td>&nbsp;</td>
              <th>Total</span></th>
              <td  scope="col">54.4</span></td>
            </tr>
          </tbody>
        </table>
        <br/><br/><br/><br/><br/><br/><br/><br/><br/><br/>
        Here is your QR code to show to a member of staff for checkout<br/>
        <br/><br/><br/>
        <img src="cid:image1 alt="Your QR Code">
        </body>
        </html>
    """

    # Add the HTML
    emailBody = MIMEText(html, 'html')


    # first image
    fp = open('app/qrCode.png','rb')
    msgImage = MIMEImage(fp.read())
    fp.close()
    msgImage.add_header('Content-ID','<image1>')
    msg.attach(msgImage)

    # second image
    #fp = open('app/emailBackground.png','rb')
    #msgImage2 = MIMEImage(fp.read())
    #fp.close()
    #msgImage2.add_header('Content-ID','<image2>')
    #msg.attach(msgImage2)




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
