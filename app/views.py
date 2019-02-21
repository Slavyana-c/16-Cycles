from flask import render_template, flash, url_for, redirect
from app import app, db, bcrypt, admin, models
from .forms import NewUserForm, LoginForm, SelectDates
from app.models import Users

# all imports for sending emails
import smtplib
# from email.MIMEMultipart import MIMEMultipart
# from email.MIMEText import MIMEText
# from email.MIMEBase import MIMEBase
# from email.MIMEImage import MIMEImage
# from email import encoders

# all imports for QR Code Generation
import pyqrcode
from flask_admin.contrib.sqla import ModelView

admin.add_view(ModelView(Users, db.session))




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
	if form.validate_on_submit():
		pwrd_hash = bcrypt.generate_password_hash(form.password.data).decode('utf-8')
		user = Users(email=form.email.data.lower(),
		 			 password=pwrd_hash,
					 contact_number=form.contact_number.data.lower())
		db.session.add(user)
		db.session.commit()
		# flash('Account created. You are now able to log in', 'success')
		return redirect(url_for('login'))

	return render_template("sign_up.html", form=form)


@app.route('/login', methods=['GET', 'POST'])
def login():
	form = LoginForm()
	return render_template("login.html", form=form)

# @app.route('/qr', methods=['GET', 'POST'])
# def qr():
#
#     # generating the QR code
#     url = pyqrcode.create('https://ksassets.timeincuk.net/wp/uploads/sites/55/2016/07/2015_PeepShow_Mark2_Press_111115-920x610.jpg')
#     url.png('app/qrCode.png', scale=6) # nice and big
#
#
#
#
#     # setting up email things
#     sendingAddress = "16.cycles.recipt@gmail.com"
#     sendingPassword = "phatgitproject"
#     receivingAddress = "jonathancharlesalderson@gmail.com"
#
#     msg = MIMEMultipart()
#
#     msg['From'] = "16 Cycles Rentals"
#     msg['To'] = receivingAddress
#     msg['Subject'] = "Your Reciept From Today"
#
#
#     # actual body of the email
#     html = """\
#         <html>
#         <head>
#         	<title></title>
#         	<link href="https://svc.webspellchecker.net/spellcheck31/lf/scayt3/ckscayt/css/wsc.css" rel="stylesheet" type="text/css" />
#         	<link href="https://svc.webspellchecker.net/spellcheck31/lf/scayt3/ckscayt/css/wsc.css" rel="stylesheet" type="text/css" />
#         	<link href="https://svc.webspellchecker.net/spellcheck31/lf/scayt3/ckscayt/css/wsc.css" rel="stylesheet" type="text/css" />
#         </head>
#         <body aria-readonly="false" style="cursor: auto;">
#         <h3><span style="font-family:arial,helvetica,sans-serif">Thank you for renting with us today</span></h3>
#         <span style="font-family:arial,helvetica,sans-serif">Please find attached below your recipt<br />
#         <br />
#         Username : jonathanAlderson<br />
#         Checkout&nbsp; : 15/02/19<br />
#         More detail: loren&nbsp;ipsum<br />
#         dolor eptium: pera equatus<br />
#         pectar melao: perus deulium</span>
#
#         <table align="center" border="1" cellpadding="1" cellspacing="1" style="width:500px">
#         	<thead>
#         		<tr>
#         			<th scope="col"><span style="font-family:arial,helvetica,sans-serif">Bike</span></th>
#         			<th scope="col"><span style="font-family:arial,helvetica,sans-serif">Start Date</span></th>
#         			<th scope="col"><span style="font-family:arial,helvetica,sans-serif">End Date</span></th>
#         			<th scope="col"><span style="font-family:arial,helvetica,sans-serif">Price</span></th>
#         		</tr>
#         	</thead>
#         	<tbody>
#         		<tr>
#         			<td><span style="font-family:courier new,courier,monospace">Carrera&nbsp;kraken</span></td>
#         			<td><span style="font-family:courier new,courier,monospace">15/02/19</span></td>
#         			<td><span style="font-family:courier new,courier,monospace">21/02/19</span></td>
#         			<td><span style="font-family:courier new,courier,monospace">37.6</span></td>
#         		</tr>
#         		<tr>
#         			<td><span style="font-family:courier new,courier,monospace">Boardman MTB 8.9</span></td>
#         			<td><span style="font-family:courier new,courier,monospace">25/02/19</span></td>
#         			<td><span style="font-family:courier new,courier,monospace">27/02/19</span></td>
#         			<td><span style="font-family:courier new,courier,monospace">16.8</span></td>
#         		</tr>
#         		<tr>
#         			<td>&nbsp;</td>
#         			<td>&nbsp;</td>
#         			<td><span style="font-family:courier new,courier,monospace">Total</span></td>
#         			<td><span style="font-family:courier new,courier,monospace">54.4</span></td>
#         		</tr>
#         	</tbody>
#         </table>
#         <br />
#         <br />
#         <span style="font-family:arial,helvetica,sans-serif">Here is your QR code to show to a member of staff for checkout</span><br />
#         <br />
#         <br />
#         <br />
#         <img src="cid:image1" alt="Your QR Code">
#         </body>
#         </html>
#     """
#
#     # Add the HTML
#     emailBody = MIMEText(html, 'html')
#
#
#     # opening the image image
#     fp = open('app/qrCode.png','rb')
#     msgImage = MIMEImage(fp.read())
#     fp.close()
#
#     # defining image
#     msgImage.add_header('Content-ID','<image1>')
#     msg.attach(msgImage)
#     msg.attach(emailBody)
#
#     # setup email sending
#     server = smtplib.SMTP('smtp.gmail.com', 587)
#     server.starttls()
#     server.login(sendingAddress, sendingPassword)
#     text = msg.as_string()
#
#     # commented out to stop spamming
#     server.sendmail(sendingAddress,receivingAddress , msg.as_string())
#     server.quit()
#
#     # display webpage saying it worked
#     return render_template("qr.html")
