from flask import render_template
from app import app
from .forms import NewUserForm, LoginForm

# all imports for sending emails
import smtplib
from email.MIMEMultipart import MIMEMultipart
from email.MIMEText import MIMEText
from email.MIMEBase import MIMEBase
from email import encoders

# all imports for QR Code Generation
import pyqrcode


@app.route('/')
def home():
    return render_template("home.html")


@app.route('/browse')
def browse():
    return render_template("browse.html") # this is for the shop page


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

    url = pyqrcode.create('http://uca.edu')
    print(url.text())

    qrCode = url.text()
    qrCode = qrCode.replace("1","#")
    qrCode = qrCode.replace("0"," ")

    print(qrCode)



    # sending the email
    sendingAddress = "16.cycles.recipt@gmail.com"
    sendingPassword = "phatgitproject"
    receivingAddress = "jonathancharlesalderson@gmail.com"

    msg = MIMEMultipart()

    msg['From'] = "16 Cycles Rentals"
    msg['To'] = receivingAddress
    msg['Subject'] = "Your Reciept From Today"


    html = """\
<html>
<head>
	<title></title>
	<link href="https://svc.webspellchecker.net/spellcheck31/lf/scayt3/ckscayt/css/wsc.css" rel="stylesheet" type="text/css" />
	<link href="https://svc.webspellchecker.net/spellcheck31/lf/scayt3/ckscayt/css/wsc.css" rel="stylesheet" type="text/css" />
	<link href="https://svc.webspellchecker.net/spellcheck31/lf/scayt3/ckscayt/css/wsc.css" rel="stylesheet" type="text/css" />
</head>
<body aria-readonly="false" style="cursor: auto;">
<h3><span style="font-family:arial,helvetica,sans-serif">Thank you for renting with us today</span></h3>
<span style="font-family:arial,helvetica,sans-serif">Please find attached below your recipt<br />
<br />
Username : jonathanAlderson<br />
Checkout&nbsp; : 15/02/19<br />
More detail: loren&nbsp;ipsum<br />
dolor eptium: pera equatus<br />
pectar melao: perus deulium</span>

<table align="center" border="1" cellpadding="1" cellspacing="1" style="width:500px">
	<thead>
		<tr>
			<th scope="col"><span style="font-family:arial,helvetica,sans-serif">Bike</span></th>
			<th scope="col"><span style="font-family:arial,helvetica,sans-serif">Start Date</span></th>
			<th scope="col"><span style="font-family:arial,helvetica,sans-serif">End Date</span></th>
			<th scope="col"><span style="font-family:arial,helvetica,sans-serif">Price</span></th>
		</tr>
	</thead>
	<tbody>
		<tr>
			<td><span style="font-family:courier new,courier,monospace">Carrera&nbsp;kraken</span></td>
			<td><span style="font-family:courier new,courier,monospace">15/02/19</span></td>
			<td><span style="font-family:courier new,courier,monospace">21/02/19</span></td>
			<td><span style="font-family:courier new,courier,monospace">37.6</span></td>
		</tr>
		<tr>
			<td><span style="font-family:courier new,courier,monospace">Boardman MTB 8.9</span></td>
			<td><span style="font-family:courier new,courier,monospace">25/02/19</span></td>
			<td><span style="font-family:courier new,courier,monospace">27/02/19</span></td>
			<td><span style="font-family:courier new,courier,monospace">16.8</span></td>
		</tr>
		<tr>
			<td>&nbsp;</td>
			<td>&nbsp;</td>
			<td><span style="font-family:courier new,courier,monospace">Total</span></td>
			<td><span style="font-family:courier new,courier,monospace">54.4</span></td>
		</tr>
	</tbody>
</table>
<br />
<br />
<span style="font-family:arial,helvetica,sans-serif">Here is your QR code to show to a member of staff for checkout</span><br />
<br />
<br />
<br />
<span style="font-family:lucida sans unicode,lucida grande,sans-serif"><img alt="" src="https://gitlab.com/JonathanAlderson/16-cycles/wikis/uploads/7ad73b0cb1919fdf6e715ed72e66ef43/HomePage.jpg" style="float:left; height:141px; width:251px" /></span></body>
</html>
    """
    # Add the HTML
    emailBody = MIMEText(html, 'html')


    msg.attach(emailBody)

    server = smtplib.SMTP('smtp.gmail.com', 587)
    server.starttls()
    server.login(sendingAddress, sendingPassword)
    text = msg.as_string()

    # commented out to stop spamming
    server.sendmail(sendingAddress,receivingAddress , msg.as_string())
    server.quit()

    return render_template("qr.html")
