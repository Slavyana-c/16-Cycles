from flask import render_template
from app import app
from .forms import NewUserForm, LoginForm

# all imports for sending emails
import smtplib
from email.MIMEMultipart import MIMEMultipart
from email.MIMEText import MIMEText
from email.MIMEBase import MIMEBase
from email import encoders

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

    sendingAddress = "16.cycles.recipt@gmail.com"
    sendingPassword = "phatgitproject"
    receivingAddress = "jonathancharlesalderson@gmail.com"

    msg = MIMEMultipart()

    msg['From'] = sendingAddress
    msg['To'] = receivingAddress
    msg['Subject'] = "Your Reciept From Today"

    body = "Thank you for renting your bike with us Today\nPlease find your summary and QR code below"

    msg.attach(MIMEText(body, 'plain'))


    server = smtplib.SMTP('smtp.gmail.com', 587)
    server.starttls()
    server.login(sendingAddress, sendingPassword)
    text = msg.as_string()
    server.sendmail(sendingAddress,receivingAddress , text)
    server.quit()

    return render_template("qr.html")
