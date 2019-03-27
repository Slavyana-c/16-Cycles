from flask import render_template, flash, url_for, redirect, request, abort
from app import app, db, bcrypt, admin, models
from app.models import Users,Bike_Types,Bikes,Shops,Rental_Rates,Orders,Rented_Bikes
from .forms import NewUserForm, LoginForm, SelectDates, AppliedFilters, ExtendDate, PasswordChangeForm, PaymentForm
from sqlalchemy import and_, or_

# all imports for sending emails
import smtplib
from email.mime.multipart import MIMEMultipart
from email.mime.text import MIMEText
from email.mime.base import MIMEBase
from email.mime.image import MIMEImage
from email import encoders

# datetime things
import datetime,time
from datetime import timedelta

# all imports for QR Code Generation
import pyqrcode
from flask_admin.contrib.sqla import ModelView
from flask_login import login_user, logout_user, current_user, login_required
admin.add_view(ModelView(Users, db.session))
admin.add_view(ModelView(Bike_Types, db.session))
admin.add_view(ModelView(Bikes, db.session))
admin.add_view(ModelView(Shops, db.session))
admin.add_view(ModelView(Rental_Rates, db.session))
admin.add_view(ModelView(Orders, db.session))
admin.add_view(ModelView(Rented_Bikes, db.session))

@app.route('/')
def home():
    return render_template("home.html")

@app.route('/about')
def about():
    return render_template("about.html") # redirect to the about page

@app.route('/meetOurStaff')
def meetOurStaff():
    return render_template("meetOurStaff.html") # redirect to the about page

@app.route('/browse',methods=['GET','POST'])
# lots of default arguments given here
# def browse(startWindow=datetime.datetime.now(),
#            endWindow=datetime.datetime.now()+timedelta(days=1),
#            shopID = 1):
def browse(startWindow=datetime.datetime.today(),
           endWindow=datetime.datetime.today()+timedelta(days=1),
           shopID = 1):
    form = SelectDates()
    if form.validate_on_submit():
        startWindow = form.start_date.data
        print(type(startWindow))
        # startWindow = startWindow.date()
        endWindow = form.end_date.data
        print(type(endWindow))
        # endWindow = endWindow.date()

    # task = models.Tasks(title=form.title.data,
    #                     description=form.description.data,
    #                     completion_date=form.completion_date.data,
    #                     user=current_user.id)
    # startWindow = request.args.get('start', default = datetime.datetime.now(), type = datetime)
    # endWindow = request.args.get('end',default = datetime.datetime.now()+timedelta(days=1), type = datetime)
    # shopID = request.args.get('id', default = 1, type = int)
    filterForm = AppliedFilters()
    # if filterForm.validate_on_submit():
    #     shopID = request.filterForm['shop']
    form = SelectDates();
    if form.validate_on_submit():
        print("Button pressed or somethign")
    bikeTypes = Bike_Types.query.all()
    bikes = Bikes.query.filter_by(shop_id=shopID).all()
    rentalRates = Rental_Rates.query.all()
    orders = Orders.query.all()
    rentedBikes = Rented_Bikes.query.all()
    bikesToRemove = [] # stores the ID's of bikes we need to remove
    i = 0
    while(i < len(rentedBikes)):
        # print("startWindow", end='| ')
        # print(     startWindow,end=' ')
        # print(type(startWindow))
        # print("rentedBikes[i].start_date.date()", end='| ')
        # print(     rentedBikes[i].start_date.date(), end=' ')
        # print(type(rentedBikes[i].start_date.date()))

        # print(type(startWindow))
        # print(type(rentedBikes[i].start_date))
        # checks to see if the bike is available within the given dates
        try:
            if(rentedBikes[i].start_date.date() <= startWindow and rentedBikes[i].end_date.date() >= startWindow or
               rentedBikes[i].start_date.date() >= startWindow and rentedBikes[i].start_date.date() <= endWindow):
                bikesToRemove.append(rentedBikes[i].bike_id)
        except: # catch the exception when the start and end windows are datetime already (catches TypeError)
            if(rentedBikes[i].start_date <= startWindow and rentedBikes[i].end_date >= startWindow or
               rentedBikes[i].start_date >= startWindow and rentedBikes[i].start_date <= endWindow):
                bikesToRemove.append(rentedBikes[i].bike_id)
        i += 1

    # if the start date is bigger than the end date, then no bikes should
    # be shown to the user
    if(startWindow > endWindow):
        bikes = []

    # remove the bikes that will be rented in the given time
    i = 0
    while(i < len(bikes)):
        if(bikes[i].bike_type_id in bikesToRemove):
            bikes = bikes[:i] + bikes[i+1:]
        else:
            i+=1

    # now the only bikes shown to the user are the ones they can actually rent
    return render_template("browse.html", filterForm=filterForm,form=form,data=[bikes,bikeTypes,rentalRates,startWindow,endWindow]) # redirect to the bike search page, giving all the data

# OLD version of bikePage
# @app.route('/bikePage')
# def bikePage():
#     form = SelectDates();
#     data = Bike_Types.query.all()[0]#(brand='Voodoo')
#     return render_template("bikePage.html", form=form) # redirect to the bike search page


@app.route('/bikePage/',methods=['GET', 'POST'])
def bikePage():
    brand = request.args.get('brand', default = 'BRAND', type = str)
    model = request.args.get('model', default = 'MODEL', type = str)
    rentStart = request.args.get('rentStartDate',default='START',type = None)
    rentEnd   = request.args.get('rentEndDate', default='END',type = None)
    bikeId = request.args.get('bike_id', default = 'bike_id', type = str)

    # doing string formatting
    rentStartDate = datetime.date(int(rentStart.split("-")[0]),int(rentStart.split("-")[1]),int(rentStart.split("-")[2][:2]))
    rentEndDate = datetime.date(int(rentEnd.split("-")[0]),int(rentEnd.split("-")[1]),int(rentEnd.split("-")[2][:2]))

    thisRentalRate = Rental_Rates.query.filter(Rental_Rates.bike_type_id == bikeId).first()
    form = SelectDates();
    data = Bike_Types.query.filter(and_(Bike_Types.brand == brand, Bike_Types.model == model)).first()
    image = data.image

    numberOfDays = (rentEndDate-rentStartDate).days
    bikeRentPrice = calculateRentPrice(numberOfDays,thisRentalRate)

    return render_template("bikePage.html", data=data, form=form,rentStart=rentStartDate,rentEnd=rentEndDate,rentInfo=[bikeRentPrice,thisRentalRate,numberOfDays]) # redirect to the bike search page

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
	if current_user.is_authenticated:
		return redirect(url_for('home'))
	form = NewUserForm()
	if form.validate_on_submit():
		pwrd_hash = bcrypt.generate_password_hash(form.password.data).decode('utf-8')
		user = Users(email=form.email.data.lower(),
		 			 password=pwrd_hash,
					 contact_number=form.contact_number.data.lower())
		db.session.add(user)
		db.session.commit()
		flash('Account created. You are now able to log in', 'success')
		return redirect(url_for('login'))

	return render_template("sign_up.html", form=form)


@app.route('/login', methods=['GET', 'POST'])
def login():
	if current_user.is_authenticated:
		return redirect(url_for('home'))
	form = LoginForm()
	if form.validate_on_submit():
		user = Users.query.filter_by(email=form.email.data).first()
		if user and bcrypt.check_password_hash(user.password, form.password.data):
			login_user(user, remember=form.remember.data)
			next_page = request.args.get('next')
			if current_user.is_authenticated:
				flash('You have logged in', 'success')

			return redirect(next_page) if next_page else redirect(url_for('home'))
		else:
			flash('Log-in attempt unsuccessful, please check email and password', 'danger')
	return render_template("login.html", form=form)

@app.route('/logout')
def logout():
	logout_user()
	flash('You have successfully logged out', 'success')
	return redirect(url_for('home'))


def calculateRentPrice(numberOfDays,rentalRates):
    # we have a start date
    # and an end date
    # so we can find out the number of days
    # we have a a daily rate, weekly rate and monthly rate

    # we round the rental rate to the nearest 10p
    # so it isn't as bad for the user



    print("\nRental Rate")
    print(numberOfDays)
    print(rentalRates.daily_rate,rentalRates.weekly_rate,rentalRates.monthly_rate)

    # less than a week case
    if(numberOfDays < 7):
        # return the number of days * the weekly raet
        return rentalRates.daily_rate * numberOfDays

    # less than a month case
    if(numberOfDays < 28):
        # we divide the weekly rate by seven and multiply my number of days
        return round((rentalRates.weekly_rate/7) * numberOfDays,1)

    # more than a month
    # so we take the monthly rate / 28 and multiply by number of days
    return round((rentalRates.monthly_rate/28) * numberOfDays,1)





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

def payForm(bikesRenting):
    form = PaymentForm()
    if form.validate_on_submit():
        qr(form.email.data, bikesRenting)
        bikePage(1)
    return render_template("payment.html", form=form)

@app.route('/qr', methods=['GET', 'POST'])
def qr(receivingAddress, bikesRented):

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
