from config import SQLALCHEMY_DATABASE_URI
from app import db, models
import os.path
import random

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


def addShops():
    # this function creates all the details for the stores
    names = ["Leeds University Union","Headingley","City Centre"]
    addresses = ["Lifton Place, Leeds, LS2 9JZ","2 St Michael's Road, Leeds LS6 3AW","Unit 1, New Station St, Leeds LS1 5DE"]
    numbers = ["01133801400","01132785836","01132469132"]
    for i in range(3):
        newShop = models.Shops(location_name=names[i],
                               address=addresses[i],
                               contact_number=numbers[i])
        db.session.add(newShop)
        db.session.commit()

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

addBikeTypes()
addShops()
addIndividualBikes()
