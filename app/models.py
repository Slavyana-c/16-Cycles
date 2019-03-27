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
    latitudes = ["53.806576","53.789944","53.796104"]
    longitudes = ["-1.555882","-1.560632","-1.547351"]
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
    numOfBikesToAdd = 500
    bikeIDs = []
    allBikes = models.Bike_Types.query.all()
    for bike in allBikes:
        bikeIDs.append(bike.id)

    shopIDs = []
    allShops = models.Shops.query.all()
    for shop in allShops:
        shopIDs.append(shop.id)

    for i in range(numOfBikesToAdd):
        print("Adding Bike")
        daysUsed = random.randint(10,100)
        timesRented = int(daysUsed / (random.randint(1,5)))
        timesRepaired = random.randint(0,10)
        newBike = models.Bikes(days_used=daysUsed,times_rented=timesRented,times_repaired=timesRepaired,available=True,bike_type_id=random.choice(bikeIDs),shop_id=random.choice(shopIDs))
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


def addStaff():

    names = ["Jonathan","Matthew","Slavyana","Domantas","Ciaran","Andy"]
    secondNames = ["Alderson","Cumber","Chervenkondeva","Dilys","Brennan","Parkes"]
    addresses = ["70 Royal Park Road","The Tannery Flat 31","Charles Morris","Leodis","Liberty Dock","Surrey"]

    for i in range(len(names)):
        print("Adding staff member" + names[i] + " " + secondNames[i])
        newStaff = models.Staff(email=names[i] + secondNames[i] + "@gmail.com",
                              password="pass",
                              contact_number="07" + str(random.randint(100000000,999999999)),
                              name=names[i] + " " + secondNames[i],
                              address = addresses[i],
                              admin=True,
                              shop_id = (i+2)//2)
        db.session.add(newStaff)
    db.session.commit()
    time.sleep(2)

def addUsersAndRentals():

    numberOfUsers = 100
    numberOfBikes = 500
    alreadyRentedBikes = []
    usersRentStart = []
    names = ["Tom","Alice","Peter","Gabriel","Tohfah","Della","June","Matthew","Conor","Thomas","James","Stephen","Jane","Richard","Lisa"]
    secondNames = ["Alderson","Carey","Yates","Robinson","Faucher","Fuhn","Amis","McNiel","Hacket","Calle","Court","Smith"]
    for i in range(numberOfUsers):
        firstName = random.choice(names)
        secondName = random.choice(secondNames)
        print("Adding " + firstName + " " + secondName)
        newUser = models.Users(email=firstName + secondName + str(random.randint(0,10000)) + "@gmail.com",
                              password="pass",
                              contact_number="07" + str(random.randint(100000000,999999999)),
                              times_rented=random.randint(0,10))
        db.session.add(newUser)
        db.session.commit()
    time.sleep(2)
    for i in range(numberOfUsers):
            year = 2019
            month = random.randint(1,12)
            day = random.randint(1,27)
            usersRentStart.append(datetime.date(year,month,day))
            price = random.randint(0,150)
            print("Adding order " + str(year) + "/" + str(month) + "/" + str(day) + ": " + str(price))
            newOrder = models.Orders(date=datetime.date(year,month,day),
                                    total_price=price,
                                    user_id=i+1,
                                   )
            db.session.add(newOrder)
    db.session.commit()
    time.sleep(2)

    for i in range(numberOfUsers):
        start = usersRentStart[i]
        end = usersRentStart[i] + timedelta(days=random.randint(2,16))

        bikeToRent = random.randint(1,numberOfBikes-1)
        while bikeToRent in alreadyRentedBikes:
            bikeToRent = random.randint(1,numberOfBikes-1)
        alreadyRentedBikes.append(bikeToRent)

        print("Adding rental from ",start," to ",end," with ",bikeToRent)
        newRental = models.Rented_Bikes(start_date = start, end_date= end,price = random.randint(10,100),bike_id=bikeToRent,order_id=i+1)
        db.session.add(newRental)
    db.session.commit()
    time.sleep(2)



addShops()
addBikeTypes()
addIndividualBikes()
addRentalRates()
addUsersAndRentals()
addStaff()
