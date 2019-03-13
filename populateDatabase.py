from config import SQLALCHEMY_DATABASE_URI
from app import db, models
import os.path



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
