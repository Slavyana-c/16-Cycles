from flask import render_template, flash, url_for, redirect, request, abort, session
from app import app, db, bcrypt, admin, models, mail
from app.models import Users,Bike_Types,Bikes,Shops,Rental_Rates,Orders,Rented_Bikes,Payment_Methods
from .forms import (NewUserForm, LoginForm, SelectDates, AppliedFilters,
                    ExtendDate, PasswordChangeForm, RequestPasswordForm,
                    NewPasswordForm, PaymentForm, RentButton, DisableFilters, SelectPaymentForm)
                    # NewPasswordForm, PaymentForm, RentButton, SelectPaymentForm)
from flask_mail import Message
from sqlalchemy import and_, or_

# all imports for sending emails
import smtplib
import json
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



class RentedView(ModelView):
    column_display_pk = True # optional, but I like to see the IDs in the list
    column_hide_backrefs = False
    column_list = ('id', 'start_date', 'end_date', 'price', 'bike_id', 'order_id')

class DetailedView(ModelView):
    column_display_pk = True # optional, but I like to see the IDs in the list
    column_hide_backrefs = False


admin.add_view(DetailedView(Users, db.session))
admin.add_view(DetailedView(Bike_Types, db.session))
admin.add_view(DetailedView(Bikes, db.session))
admin.add_view(DetailedView(Shops, db.session))
admin.add_view(DetailedView(Rental_Rates, db.session))
admin.add_view(DetailedView(Orders, db.session))
admin.add_view(DetailedView(Rented_Bikes, db.session))
admin.add_view(DetailedView(Payment_Methods, db.session))

def saveChoices(shopID,typeChosen,ageChosen,colourChosen,brandChosen):
    choices = {'shop' : shopID, 'type' : typeChosen, 'age' : ageChosen,
               'colour' : colourChosen, 'brand' : brandChosen}
    print(choices)

@app.route('/')
def home():
    return render_template("home.html")

@app.route('/about')
def about():
    shops = Shops.query.all()
    bikeCount = []
    for shop in shops:
        bikesInShop= Bikes.query.filter(Bikes.shop_id==shop.id).count()
        bikeCount.append(bikesInShop)

    return render_template("about.html", shops=shops, bikeCount=bikeCount) # redirect to the about page

@app.route('/meetOurStaff')
def meetOurStaff():
    return render_template("meetOurStaff.html") # redirect to the about page

@app.route('/browse',methods=['GET','POST'])
# lots of default arguments given here
# def browse(startWindow=datetime.datetime.now(),
#            endWindow=datetime.datetime.now()+timedelta(days=1),
#            shopID = 1):

# def browse(startWindow=datetime.datetime.today(),
#            endWindow=datetime.datetime.today()+timedelta(days=1),
#            shopID = 1):
# ******************************************************************************************************************************************
#
# '||
#  || ...  ... ..    ...   ... ... ...  ....    ....
#  ||'  ||  ||' '' .|  '|.  ||  ||  |  ||. '  .|...||
#  ||    |  ||     ||   ||   ||| |||   . '|.. ||
#  '|...'  .||.     '|..|'    |   |    |'..|'  '|...'
#
#
# ******************************************************************************************************************************************
def browse():
    form_a = SelectDates(prefix='a')
    # filterForm = AppliedFilters()
    form_b = AppliedFilters(prefix='b')
    form_c = DisableFilters(prefix='c')
    # form_d = AppliedFilters(prefix='d')
    # form_e = AppliedFilters(prefix='e')
    # filterForm = AppliedFilters(prefix="form_b")

    bikeTypes = Bike_Types.query.all()
    defaultflag = False

    bikes = Bikes.query.all() # if no shop was chosen, we display all bikes
    rentalRates = Rental_Rates.query.all()
    orders = Orders.query.all()
    rentedBikes = Rented_Bikes.query.all()
    bikesToRemove = [] # stores the ID's of bikes we need to remove
    filteredOutBikeIDs = []
    filterListForDisplay = {} # filter list to be displayed in the website
    shopsByID = ["University", "Town", "Headingley"]
    #filters={} # filter dictionary, storing all selected filters

    try:
        print("TRY CONDITION")
        bufferStart = session['savedStartDate']
        bufferEnd = session['savedEndDate']


        print(bufferStart)
        print(bufferEnd)

        try:
            print("try1")
            startWindow = datetime.datetime.strptime(bufferStart, '%Y-%m-%d %H:%M:%S.%f')
            endWindow = datetime.datetime.strptime(bufferEnd, '%Y-%m-%d %H:%M:%S.%f')
        except:
            try:
                print("try2")
                bufferStart = bufferStart.date()
                startWindow = datetime.datetime.strptime(bufferStart, '%Y-%m-%d %H:%M:%S.%f')
                endWindow = datetime.datetime.strptime(bufferEnd, '%Y-%m-%d %H:%M:%S.%f')
            except:
                print("try3")
                bufferEnd = bufferEnd.date()
                startWindow = datetime.datetime.strptime(bufferStart, '%Y-%m-%d %H:%M:%S.%f')
                endWindow = datetime.datetime.strptime(bufferEnd, '%Y-%m-%d %H:%M:%S.%f')
        # startWindow = datetime.strptime(session['savedStartDate'], '%b %d %Y %I:%M%p')
        # endWindow = datetime.strptime(session['savedEndDate'], '%b %d %Y %I:%M%p')
        # startWindow = session['savedStartDate'] #.strptime('%m/%d/%Y')
        # endWindow = session['savedEndDate'] #.strptime('%m/%d/%Y')
        print("\n")
        print(startWindow)
        print(type(startWindow))
        print(endWindow)
        print(type(endWindow))
        print("\n")
    except:
        print("EXCEPT CONDITION")
        startWindow=datetime.datetime.today()
        endWindow=datetime.datetime.today()+timedelta(days=1)
        print(startWindow)
        print(type(startWindow))
        print(endWindow)
        print(type(endWindow))

# ******************************************************************************
#
#   .'|.                            '||''|.
# .||.     ...   ... ..  .. .. ..    ||   ||
#  ||    .|  '|.  ||' ''  || || ||   ||'''|.
#  ||    ||   ||  ||      || || ||   ||    ||
# .||.    '|..|' .||.    .|| || ||. .||...|'
#
# ******************************************************************************
    if form_b.submit.data:
        # shopID = request.filterForm['shop']
        shopID = form_b.shopChoice.data
        typeChosen = form_b.typeChoice.data
        ageChosen = form_b.ageChoice.data
        colourChosen = form_b.colourChoice.data
        brandChosen = form_b.brandChoice.data

        saveChoices(shopID,typeChosen,ageChosen,colourChosen,brandChosen)

        # shopID = request.form.getlist("users")
        bikeTypes = Bike_Types.query.all()
        bikes = []
        if (typeChosen == "None" and ageChosen == "None"
        and colourChosen == "None" and brandChosen == "None" and shopID != "None"):
            print('only shop chosen')
            # just get the bikes from the shop
            filterListForDisplay["Shop"] = shopsByID[int(shopID)-1]
            bikes = Bikes.query.filter_by(shop_id=shopID).all()
        else:
            # else if shop and something else was chosen
            # (we have to split the shop and others because they are
            #  stored in two different database models)
            filters={} # filter dictionary, storing all selected filters

            # bikesFilteredOutFromBike_Types = Bike_Types.query.filter_by(use_type=typeChosen,user_type=ageChosen,colour=colourChosen,brand=brandChosen).all()
            if typeChosen!="None":
                filters['use_type'] = typeChosen
                filterListForDisplay['Type'] = typeChosen
            if ageChosen!="None":
                filters['user_type'] = ageChosen
                filterListForDisplay['Age'] = ageChosen
            if colourChosen!="None":
                filters['colour'] = colourChosen
                filterListForDisplay['Colour'] = colourChosen
            if brandChosen!="None":
                filters['brand'] = brandChosen
                filterListForDisplay['Brand'] = brandChosen

            # unpacking the argument dictionary (**filters):
            print("printing the filter dict")
            print (filters)
            bikesFilteredOutFromBike_Types = Bike_Types.query.filter_by(**filters).all()
            # bikesFilteredOutFromBike_Types = Bike_Types.query.filter_by(brand="Boardman").all()

            # we keep a list of bike IDs from Bike_Type database model:
            for bike in bikesFilteredOutFromBike_Types:
                print(bike)
                filteredOutBikeIDs.append(bike.id)
            print(filteredOutBikeIDs)
            # Set the default shop:
            if shopID == "None":
                shopID = "1"
            for ID in filteredOutBikeIDs:
                # if shop is not selected, then we just display all bikes matching
                # the IDs in 'Bikes' database model:
                if shopID == "None":
                    oneBike = Bikes.query.filter_by(bike_type_id=ID).first()
                else:
                    filterListForDisplay["Shop"] = shopsByID[int(shopID)-1]
                    oneBike = Bikes.query.filter_by(bike_type_id=ID,shop_id=shopID).first()
                # filter out 'None' bikes
                if oneBike is None:
                    print("DO NOT ADD")
                else:
                    print("{")
                    print(oneBike)
                    print(oneBike.bike_type_id)
                    print("}")
                    # add to the 'bikes' list to be displated on the browse page:
                    bikes.append(oneBike)
                # print(bikes)
            print("END OF EQUATING IDS IN BIKES DB")

            print("PRINTING BIKES THAT SHOULD BE DISPLAYED:")
            print(bikes)

            bikeTypeId = Bikes.query.filter_by(id=1).first().bike_type_id
            bikeColour = Bike_Types.query.filter_by(id=bikeTypeId).all()

            print(bikeColour)

            for bike in bikes:
                print (bike)

        rentalRates = Rental_Rates.query.all()
        orders = Orders.query.all()
        rentedBikes = Rented_Bikes.query.all()
        print("Filters applied")

# ******************************************************************************
#
#   .'|.                              ..|'''.|
# .||.     ...   ... ..  .. .. ..   .|'     '
#  ||    .|  '|.  ||' ''  || || ||  ||
#  ||    ||   ||  ||      || || ||  '|.      .
# .||.    '|..|' .||.    .|| || ||.  ''|....'
#
#
# ******************************************************************************

    # if form_c.validate_on_submit():
    if (form_c.Brand.data) or (form_c.Colour.data) or (form_c.Age.data) or (form_c.Type.data) or (form_c.Shop.data):
        defaultflag = False
        toRemove = form_c.data
        print("DATA RECEIVED:")
        print(toRemove)
        optionToRemove = "none"
        for tag, choice in toRemove.items():
            if choice == True:
                optionToRemove = tag
                print(tag)
        print("to remove:")
        print(optionToRemove)
        # data = json.loads(request.data.decode('utf-8'))
        # data = request.GET.getlist('stat[]')
        # data = request.get_json()
        # print(data)
        # print(data['html_data'])   # should print your list
        # print("made it to here")
        # print(data)
        print("SESSION VARIABLES:")
        currentFilters = session['savedChoices']
        print(currentFilters)


        if "Shop" in currentFilters:
            shopName = currentFilters['Shop']
            if shopName == "University":
                shopID = "1"
            elif shopName == "Town":
                shopID = "2"
                defaultflag = False
            else:
                shopID = "3"
                defaultflag = False
        else:
            shopID = "1" # Set the default shop

        if "Type" in currentFilters:
            typeChosen = currentFilters['Type']
        else:
            typeChosen = "None"

        if "Age" in currentFilters:
            ageChosen = currentFilters['Age']
        else:
            ageChosen = "None"

        if "Colour" in currentFilters:
            colourChosen = currentFilters['Colour']
        else:
            colourChosen = "None"

        if "Brand" in currentFilters:
            brandChosen = currentFilters['Brand']
        else:
            brandChosen = "None"

        print(shopID)
        print(typeChosen)
        print(ageChosen)
        print(colourChosen)
        print(brandChosen)

        if optionToRemove == "Shop":
            shopID = "None"
        elif optionToRemove == "Type":
            typeChosen = "None"
        elif optionToRemove == "Age":
            ageChosen = "None"
        elif optionToRemove == "Colour":
            colourChosen = "None"
        elif optionToRemove == "Brand":
            brandChosen = "None"


        print(optionToRemove)
        print(shopID)
        print(typeChosen)
        print(ageChosen)
        print(colourChosen)
        print(brandChosen)

        # shopID = request.form.getlist("users")
        bikeTypes = Bike_Types.query.all()
        bikes = []
        if (typeChosen == "None" and ageChosen == "None"
        and colourChosen == "None" and brandChosen == "None" and shopID != "None"):
            print('only shop chosen')
            # just get the bikes from the shop
            filterListForDisplay["Shop"] = shopsByID[int(shopID)-1]
            bikes = Bikes.query.filter_by(shop_id=shopID).all()
        else:
            # else if shop and something else was chosen
            # (we have to split the shop and others because they are
            #  stored in two different database models)
            filters={} # filter dictionary, storing all selected filters

            # bikesFilteredOutFromBike_Types = Bike_Types.query.filter_by(use_type=typeChosen,user_type=ageChosen,colour=colourChosen,brand=brandChosen).all()
            if typeChosen!="None":
                filters['use_type'] = typeChosen
                filterListForDisplay['Type'] = typeChosen
            if ageChosen!="None":
                filters['user_type'] = ageChosen
                filterListForDisplay['Age'] = ageChosen
            if colourChosen!="None":
                filters['colour'] = colourChosen
                filterListForDisplay['Colour'] = colourChosen
            if brandChosen!="None":
                filters['brand'] = brandChosen
                filterListForDisplay['Brand'] = brandChosen

            # unpacking the argument dictionary (**filters):
            bikesFilteredOutFromBike_Types = Bike_Types.query.filter_by(**filters).all()

            # we keep a list of bike IDs from Bike_Type database model:
            for bike in bikesFilteredOutFromBike_Types:
                print(bike)
                filteredOutBikeIDs.append(bike.id)
            print(filteredOutBikeIDs)

            for ID in filteredOutBikeIDs:
                # if shop is not selected, then we just display all bikes matching
                # the IDs in 'Bikes' database model:
                if shopID == "None":
                    oneBike = Bikes.query.filter_by(bike_type_id=ID).first()
                else:
                    filterListForDisplay["Shop"] = shopsByID[int(shopID)-1]
                    oneBike = Bikes.query.filter_by(bike_type_id=ID,shop_id=shopID).first()
                # filter out 'None' bikes
                if oneBike is None:
                    print("DO NOT ADD")
                else:
                    print("{")
                    print(oneBike)
                    print(oneBike.bike_type_id)
                    print("}")
                    # add to the 'bikes' list to be displated on the browse page:
                    bikes.append(oneBike)
                # print(bikes)
            print("END OF EQUATING IDS IN BIKES DB")

            print("PRINTING BIKES THAT SHOULD BE DISPLAYED:")
            print(bikes)

            bikeTypeId = Bikes.query.filter_by(id=1).first().bike_type_id
            bikeColour = Bike_Types.query.filter_by(id=bikeTypeId).all()

            print(bikeColour)

            for bike in bikes:
                print (bike)

        rentalRates = Rental_Rates.query.all()
        orders = Orders.query.all()
        rentedBikes = Rented_Bikes.query.all()
        print("Filters applied")



# ****************************************************************************************************************************************
#
#   .'|.                                |
# .||.     ...   ... ..  .. .. ..      |||
#  ||    .|  '|.  ||' ''  || || ||    |  ||
#  ||    ||   ||  ||      || || ||   .''''|.
# .||.    '|..|' .||.    .|| || ||. .|.  .||.
#
#
# ****************************************************************************************************************************************

    if form_a.validate_on_submit() and form_a.submit.data:
        defaultflag = False
        print("form_a validated")
        startWindow = form_a.start_date.data
        print(type(startWindow))
        # startWindow = startWindow.date()
        endWindow = form_a.end_date.data
        print(type(endWindow))
        # endWindow = endWindow.date()

        # session['savedStartDate'] = startWindow
        # session['savedEndDate'] = endWindow
        # savedate
        session['savedStartDate'] = startWindow.strftime("%Y-%m-%d %H:%M:%S.%f")
        session['savedEndDate'] = endWindow.strftime("%Y-%m-%d %H:%M:%S.%f")

        print("SAVED DATES:")
        print(session['savedStartDate'])
        print(type(session['savedStartDate']))
        print(session['savedEndDate'])
        print(type(session['savedEndDate']))


    try:
        print("TRY CONDITION2")
        print(session['savedStartDate'])
        print(session['savedEndDate'])

        startWindow = datetime.datetime.strptime(session['savedStartDate'], '%Y-%m-%d %H:%M:%S.%f')
        savedEndDate = datetime.datetime.strptime(session['savedEndDate'], '%Y-%m-%d %H:%M:%S.%f')
        print("\n")
        print(startWindow)
        print(type(startWindow))
        print(endWindow)
        print(type(endWindow))
        print("\n")
        if type(startWindow) != type(endWindow):
            print("try2if")
            try:
                endWindow = endWindow.date()
            except:
                startWindow = startWindow.date()
            print("\n")
            print(startWindow)
            print(type(startWindow))
            print(endWindow)
            print(type(endWindow))
            print("\n")
    except:
        print("EXCEPT CONDITION2")
        getToday=datetime.datetime.today()
        getTomorrow=datetime.datetime.today()+timedelta(days=1)
        endWindow=getToday.date()
        startWindow=getTomorrow.date()
        print(startWindow)
        print(type(startWindow))
        print(endWindow)
        print(type(endWindow))

    i = 0
    while(i < len(rentedBikes)):
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

    if not form_b.submit.data :
        bikes = Bikes.query.filter_by(shop_id="1").all()
        defaultflag = True

    # if the start date is bigger than the end date, then no bikes should
    # be shown to the user
    print("before checking dates:")
    print(startWindow)
    print(endWindow)
    if(startWindow > endWindow):
        bikes = []
    # remove the bikes that will be rented in the given time
    i = 0
    while(i < len(bikes)):
        # bikes[i].bike_type_id changed to bikes[i].id
        if(bikes[i].id in bikesToRemove):
            bikes = bikes[:i] + bikes[i+1:]
        else:
            i+=1

    # now the only bikes shown to the user are the ones they can actually rent
    print("\nUpdated bikes")
    print(bikes)
    # print(bikes[0].bike_type_id)

    session['savedChoices'] =filterListForDisplay


    # now the only bikes shown to the user are the ones they can actually rent
    return render_template("browse.html",
                            disableForm=form_c,
                            filterForm=form_b,
                            form=form_a,
                            data=[bikes,bikeTypes,rentalRates,
                                  startWindow,endWindow,
                                  filterListForDisplay,
                                  defaultflag]) # redirect to the bike search page, giving all the data


# OLD version of bikePage
# @app.route('/bikePage')
# def bikePage():
#     form = SelectDates();
#     data = Bike_Types.query.all()[0]#(brand='Voodoo')
#     return render_template("bikePage.html", form=form) # redirect to the bike search page

# ****************************************************************************************************************************************
#
# '||       ||  '||              '||''|.
#  || ...  ...   ||  ..    ....   ||   ||  ....     ... .   ....
#  ||'  ||  ||   || .'   .|...||  ||...|' '' .||   || ||  .|...||
#  ||    |  ||   ||'|.   ||       ||      .|' ||    |''   ||
#  '|...'  .||. .||. ||.  '|...' .||.     '|..'|'  '||||.  '|...'
#                                                 .|....'
#
# ****************************************************************************************************************************************
@app.route('/bikePage/',methods=['GET', 'POST'])
def bikePage():
    brand = request.args.get('brand', default = 'BRAND', type = str)
    model = request.args.get('model', default = 'MODEL', type = str)
    rentStart = request.args.get('rentStartDate', default=datetime.datetime.today(),type = None)
    rentEnd   = request.args.get('rentEndDate', default=datetime.datetime.today()+timedelta(days=1),type = None)
    bikeId = request.args.get('bike_id', default = 'bike_id', type = str)
    itemId = request.args.get('item_id', default = 'item_id', type = str)
    print("\nThis printout")
    print(request.args)
    rentStartDate = datetime.date(int(rentStart.split("-")[0]),int(rentStart.split("-")[1]),int(rentStart.split("-")[2][:2]))
    rentEndDate = datetime.date(int(rentEnd.split("-")[0]),int(rentEnd.split("-")[1]),int(rentEnd.split("-")[2][:2]))

    thisRentalRate = Rental_Rates.query.filter(Rental_Rates.bike_type_id == bikeId).first()
    print(thisRentalRate)
    data = Bike_Types.query.filter(and_(Bike_Types.brand == brand, Bike_Types.model == model)).first()
    image = data.image
    bike = Bikes.query.filter_by(id=itemId).first()
    shop = Shops.query.filter_by(id=bike.shop_id).first()

    numberOfDays = (rentEndDate-rentStartDate).days
    bikeRentPrice = calculateRentPrice(numberOfDays,thisRentalRate)

    form = RentButton()
    if form.validate_on_submit():
        payForm()
        return redirect(url_for('payForm(bikeId)'))
    return render_template("bikePage.html", data=data, shop=shop, form=form, rentStart=rentStartDate, rentEnd=rentEndDate, itemId = itemId, rentInfo=[bikeRentPrice,thisRentalRate,numberOfDays]) # redirect to the bike search page

@app.route('/account')
@login_required
def account():
    form = ExtendDate()
    user_orders = Orders.query.filter_by(user_id=current_user.id).all()
    today = datetime.datetime.today()
    current_dates = []
    past_dates = []
    current_rentals = []
    past_rentals = []
    current_types = []
    past_types = []

    for order in user_orders:
        rented_bike = order.rented_bikes[0]
        bike_item = Bikes.query.filter_by(id=rented_bike.bike_id).first()
        bike_type = Bike_Types.query.filter_by(id=bike_item.bike_type_id).first()
        date = order.date.strftime("%d-%m-%Y %H:%M")

        if rented_bike.end_date >= today:
            current_dates.append(date)
            current_rentals.append(rented_bike)
            current_types.append(bike_type)
        else:
            past_dates.append(date)
            past_rentals.append(rented_bike)
            past_types.append(bike_type)


    return render_template("account.html", len_curr_rentals=len(current_rentals), len_past_rentals=len(past_rentals),
     form=form, past_rentals=past_rentals,
     current_rentals=current_rentals, current_types=current_types, past_types=past_types,
     current_dates=current_dates, past_dates=past_dates) # redirect to the account page

@app.route('/changePassword')
def changePassword():
    form = PasswordChangeForm()
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
@login_required
def logout():
	logout_user()
	flash('You have successfully logged out', 'success')
	return redirect(url_for('home'))

def send_reset_email(user):
    token = user.get_reset_token()
    msg = Message('Password Reset Request',
                  sender='noreply@16cycles.com',
                  recipients=[user.email])
    msg.body = '''To reset your password, visit the following link:
{link}


If you did not make this request, then ignore this email and no changes will be made.

'''.format(link=url_for('resetToken', token=token, _external=True))
    mail.send(msg)


@app.route("/resetPassword", methods=['GET', 'POST'])
def resetPassword():
    form = RequestPasswordForm()
    if form.validate_on_submit():
        user = Users.query.filter_by(email=form.email.data).first()
        send_reset_email(user)
        flash('An email with reset instructions has been sent to the email supplied', 'info')
        # if user verified return to account
        return redirect(url_for('login'))
    return render_template('resetPassword.html', title='Reset Password', form=form)

@app.route("/resetPassword/<token>", methods=['GET', 'POST'])
def resetToken(token):
    user = Users.verify_reset_token(token)
    if not user:
        flash('That token is invalid or expired', 'warning')
        return redirect(url_for('resetPassword'))
    form = NewPasswordForm()
    if form.validate_on_submit():
        hashed_password = bcrypt.generate_password_hash(form.password.data).decode('utf-8')
        user.password = hashed_password
        db.session.commit()
        flash('Your password has been updated.', 'success')
        return redirect(url_for('login'))
    return render_template('resetToken.html', title='Reset Password', form=form)

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
  <td>""" + bike[3] + """</span></td>
  <td>""" + bike[4] + """</span></td>
  <td>""" + bike[5] + """</span></td>
</tr>
"""
    return output

def makeCheckoutTable(databaseOutput):
    output = ""
    titles = ["UserName","Date","Time","User ID","Total Price"]
    for i in range(len(titles)):
        output += """  <tr>
    <th>""" + titles[i] + """</th>
    <td>""" + str(databaseOutput[i]) + """</td>
  </tr> """

    return output

@app.route('/paymentform', methods=['GET', 'POST'])
@login_required
def payForm():
    brand = request.args.get('brand', default = 'BRAND', type = str)
    model = request.args.get('model', default = 'MODEL', type = str)
    rentStart = request.args.get('rentStartDate', default=datetime.datetime.today(), type = None)
    rentEnd = request.args.get('rentDateEnd', default=datetime.datetime.today()+timedelta(days=1), type = None)
    rentDays = request.args.get('rentDays', type = int)
    rentCost = request.args.get('rentCost')
    itemId = request.args.get('itemId', default = 'item_id', type = str)
    bikeID = request.args.get('bike_id', default = 'bike_id', type = str)
    rentStartDate = str(rentStart.day) + "/" + str(rentStart.month) + "/" + str(rentStart.year)
    rentEndDate = rentEnd[8:] + "/" + rentEnd[5:7] + "/" + rentEnd[0:4]
    print("\n\n\n\nWe got to here")
    print(request.args)
    data = Bike_Types.query.filter(and_(Bike_Types.brand == brand, Bike_Types.model == model)).first()
    image = data.image

    cards = Payment_Methods.query.filter_by(user_id=current_user.id).all()

    print(itemId)
    cardForm = SelectPaymentForm()
    for card in cards:
        card_num = card.card_number.split("##cardname=")
        newChoice = (str(card.id), "**** " + card_num[1])
        cardForm.paymentChoice.choices.append(newChoice)


    if cardForm.validate_on_submit():
        # Save order in database
        datetimeStart = datetime.datetime.strptime(rentStartDate, '%d/%m/%Y')
        datetimeEnd = datetime.datetime.strptime(rentEndDate, '%d/%m/%Y')

        order = Orders(total_price=rentCost, user_id=current_user.id)
        db.session.add(order)
        db.session.commit()

        rental = Rented_Bikes(start_date=datetimeStart, end_date=datetimeEnd, bike_id=itemId, price=rentCost, order_id=order.id)

        db.session.add(rental)
        user = Users.query.filter_by(id=current_user.id).first()
        user.times_rented += 1

        bike = Bikes.query.filter_by(id=itemId).first()
        bike.times_rented += 1
        bike.days_used += rentDays

        bike_type = Bike_Types.query.filter_by(id=bikeID).first()
        bike_type.times_rented += 1

        db.session.commit()

        qr(current_user.email, brand, model, bikeID, rentStartDate, rentEndDate, rentCost)
        return redirect(url_for('browse'))


    form = PaymentForm()

    if form.validate_on_submit():
        # Save payment method, if selected
        if(form.save.data == True):

                date = form.expDate.data.split("/")
                month_hash = bcrypt.generate_password_hash(date[0]).decode('utf-8')
                year_hash = bcrypt.generate_password_hash(date[1]).decode('utf-8')
                card_num_pre_hash = bcrypt.generate_password_hash(form.cardNumber.data).decode('utf-8')
                card_num_hash = card_num_pre_hash + "##cardname=" + form.cardNumber.data[-4:]
                cvv_hash = bcrypt.generate_password_hash(form.cvv.data).decode('utf-8')
                payment = Payment_Methods(card_number=card_num_hash, cvv=cvv_hash, expiration_month=month_hash, expiration_year=year_hash, user_id=current_user.id)
                db.session.add(payment)
                db.session.commit()

        # Save order in database
        # Save order in database
        datetimeStart = datetime.datetime.strptime(rentStartDate, '%d/%m/%Y')
        datetimeEnd = datetime.datetime.strptime(rentEndDate, '%d/%m/%Y')

        order = Orders(total_price=rentCost, user_id=current_user.id)
        db.session.add(order)
        db.session.commit()

        rental = Rented_Bikes(start_date=datetimeStart, end_date=datetimeEnd, bike_id=itemId, price=rentCost, order_id=order.id)

        db.session.add(rental)
        user = Users.query.filter_by(id=current_user.id).first()
        user.times_rented += 1

        bike = Bikes.query.filter_by(id=itemId).first()
        bike.times_rented += 1
        bike.days_used += rentDays

        bike_type = Bike_Types.query.filter_by(id=bikeID).first()
        bike_type.times_rented += 1

        db.session.commit()

        qr(form.email.data, brand, model, bikeID, rentStartDate, rentEndDate, rentCost)
        return redirect(url_for('browse'))

    email = current_user.email
    form.email.default = email
    form.process()
    return render_template("payment.html", number_of_cards=len(cards), cardForm=cardForm, form=form, data=data, image=image, rentCost=rentCost, rentDays=rentDays, rentStart=rentStartDate, rentEnd=rentEndDate)


@app.route('/qr', methods=['GET', 'POST'])
def qr(receivingAddress, bikeBrand, bikeModel, bikeID, rentStartDate, rentEndDate, rentCost):
    # generating the QR code
    url = pyqrcode.create('https://ksassets.timeincuk.net/wp/uploads/sites/55/2016/07/2015_PeepShow_Mark2_Press_111115-920x610.jpg')
    url.png('app/qrCode.png', scale=2) # nice and big

    # we take this dummy database output for use in the emails
    order = [(bikeBrand, bikeModel, bikeID, rentStartDate, rentEndDate, rentCost)]
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
          <tbody> """ + makeBikeRentalsTable(order) + """

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

    # setup email sending3122824.3 for
    server = smtplib.SMTP('smtp.gmail.com', 587)
    server.starttls()
    server.login(sendingAddress, sendingPassword)
    text = msg.as_string()

    # commented out to stop spamming
    server.sendmail(sendingAddress,receivingAddress , msg.as_string())
    server.quit()

    # display webpage saying it worked
    return render_template("qr.html")
