from config import SQLALCHEMY_DATABASE_URI
from app import db, models
import os.path
import random
import datetime
from datetime import timedelta
import time


def readFromCSV():
    bikeData = open("bikeSpreadsheet.csv").read()  # read from the database
    bikeData = bikeData.split(",") # split by commas

    # since the last column ends with a \n, remove these newlines, which
    # is a litle bit difficult since ["price\n14"] -> ["price","14"]
    # which will cause some indexing errors, so we have to be careful.
    i = 0
    while(i<len(bikeData)):
        if("\n" in bikeData[i]):
            bikeData = bikeData[:i] + [bikeData[i].split("\n")[0]] + [bikeData[i].split("\n")[1]] + bikeData[i+1:]
        i+=1
    # remove the header and the last item which is just ''
    bikeData = bikeData[9:-1]

    return bikeData

def addBikeTypes():
    bikeData = open("bikeSpreadsheet.csv").read()  # read from the database
    bikeData = bikeData.split(",") # split by commas

    # since the last column ends with a \n, remove these newlines, which
    # is a litle bit difficult since ["price\n14"] -> ["price","14"]
    # which will cause some indexing errors, so we have to be careful.
    i = 0
    while(i<len(bikeData)):
        if("\n" in bikeData[i]):
            bikeData = bikeData[:i] + [bikeData[i].split("\n")[0]] + [bikeData[i].split("\n")[1]] + bikeData[i+1:]
        i+=1
    # remove the header and the last item which is just ''
    bikeData = bikeData[9:-1]


    # now printout the information
    for i in range(0,len(bikeData),9):
        print(bikeData[i],bikeData[i+1],bikeData[i+2],bikeData[i+3],bikeData[i+4],bikeData[i+5],bikeData[i+6],bikeData[i+7],bikeData[i+8])
        newBike = models.Bike_Types(gears=bikeData[i],weight=bikeData[i+1],brand=bikeData[i+2],model=bikeData[i+3],image=bikeData[i+4],colour=bikeData[i+5],user_type=bikeData[i+6],use_type=bikeData[i+7],times_rented=0)
        db.session.add(newBike)

    db.session.commit()
    time.sleep(2)


def addShops():
    # this function creates all the details for the stores
    names = ["Leeds University Union","Headingley","City Centre"]
    addresses = ["Lifton Place, Leeds, LS2 9JZ","2 St Michael's Road, Leeds LS6 3AW","Unit 1, New Station St, Leeds LS1 5DE"]
    numbers = ["01133801400","01132785836","01132469132"]
    latitudes = [53.807348,53.8193,53.7956]
    longitudes = [-1.558362,-1.5773,-1.5444]
    for i in range(3):
        print("Adding Shop: ",names[i])
        newShop = models.Shops(location_name=names[i],
                               address=addresses[i],
                               contact_number=numbers[i],
                               latitude=latitudes[i],
                               longitude=longitudes[i])
        db.session.add(newShop)
        db.session.commit()
    time.sleep(2)

def addIndividualBikes():
    print("Now Adding invididual bikes")

    bikeIDs = []
    allBikes = models.Bike_Types.query.all()
    for bike in allBikes:
        bikeIDs.append(bike.id)

    shopIDs = []
    allShops = models.Shops.query.all()
    for shop in allShops:
        shopIDs.append(shop.id)

    for i in range(10):
        newBike = models.Bikes(days_used=0,times_rented=0,times_repaired=0,available=True,bike_type_id=random.choice(bikeIDs),shop_id=random.choice(shopIDs))
        db.session.add(newBike)

    db.session.commit()
    time.sleep(2)

def addRentalRates():
    # for every bike, we can see how much it costs to rent it
    # rental Rental_Rates (percentage of bike price)
    #
    # day 2%
    # week 8%
    # month 20%
    dayPercent = 0.02
    weekPercent = 0.08
    monthPercent = 0.2
    bikeIDs = []
    allBikeData = readFromCSV()
    allBikes = models.Bike_Types.query.all()
    for bike in allBikes:
        bikeIDs.append(bike.id)
    for i in range(0,len(allBikeData),9):
        print("Adding bike rental rate " + str(bikeIDs[i//9]))
        bikePrice = int(allBikeData[i+8])
        newRentalRate = models.Rental_Rates(daily_rate=round(bikePrice*dayPercent),
                                            weekly_rate=round(bikePrice*weekPercent),
                                            monthly_rate=round(bikePrice*monthPercent),
                                            bike_type_id=bikeIDs[i//9]
                                            )
        db.session.add(newRentalRate)
    db.session.commit()
    time.sleep(2)

def addRentedBikes():

    # first of all add a user
    #newUser = models.Users(email="jonathancharlesalderson@gmail.com",
    #                       password="pass",
    #                       contact_number="99",
    #                       times_rented=0)
    #db.session.add(newUser)
    #db.session.commit()
    #newRental = models.Rented_Bikes(start_date)


    # then give the user an order
    #newOrder = models.Orders(date=datetime.datetime.now(),
    #                         total_price=50,
    #                         user_id=1,
    #                        )
    #db.session.add(newOrder)
    #db.session.commit()


    print(datetime.datetime.now())
    start = datetime.datetime(2019,3,26,1,1,1,1)
    end = datetime.datetime(2019,3,29,1,1,1,1)

    newRental = models.Rented_Bikes(start_date = start, end_date= end,price = 45,bike_id=4,order_id=1)
    db.session.add(newRental)
    db.session.commit()

addShops()
addBikeTypes()
addIndividualBikes()
addRentalRates()
addRentedBikes()
