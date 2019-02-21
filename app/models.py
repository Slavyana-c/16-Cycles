from app import db, app
from datetime import datetime
from flask_login import UserMixin

# The Users database model
class Users(db.Model, UserMixin):
    id = db.Column(db.Integer, primary_key=True)
    email = db.Column(db.String(100), unique=True, nullable=False)
    password = db.Column(db.String(60), nullable=False)
    contact_number = db.Column(db.String(15), nullable=False)
    staff = db.Column(db.Boolean, default=False)
    admin = db.Column(db.Boolean, default=False)

# # The Bikes database model
# class Bikes(db.Model):
#     id = db.Column(db.Integer, primary_key=True)
#     days_used = db.Column(db.Integer, default=0)
#     times_rented = db.Column(db.Integer, default=0)
#     times_repaired = db.Column(db.Integer, default=0)
#     available = db.Column(db.Boolean, default=True)
#     # Foreign keys
#     bike_type_id = db.Column(db.Integer, db.ForeignKey('bike_types.id'), nullable=False)
#     shop_id = db.Column(db.Integer, db.ForeignKey('shops.id'), nullable=False)
#     # Relationship to Bookings
#     bookings = db.relationship('Bookings', backref='bike', lazy=True)
#
# # The Bike_Types database model
# class Bike_Types(db.Model):
#     id = db.Column(db.Integer, primary_key=True)
#     brand = db.Column(db.String(50),nullable=False)
#     model = db.Column(db.String(50),nullable=False)
#     image = db.Column(db.String(20), nullable=False, default='default.jpg')
#     colour = db.Column(db.String(50),nullable=False)
#     user_type = db.Column(db.String(100),nullable=False)
#     use_type = db.Column(db.String(100),nullable=False)
#     times_rented = db.Column(db.Integer, default=0)
#     # Relationships to Bikes and Rental_Rates
#     bikes = db.relationship('Bikes', backref='bike_type', lazy=True)
#     rental_rates = db.relationship('Rental_Rates', backref='bike_type', lazy=True)
#
# # The Rental_Rates database model
# class Rental_Rates(db.Model):
#     id = db.Column(db.Integer, primary_key=True)
#     daily_rate = db.Column(db.Float, default=0.0)
#     weekly_rate = db.Column(db.Float, default=0.0)
#     monthly_rate = db.Column(db.Float, default=0.0)
#     # Foreign keys
#     bike_type_id = db.Column(db.Integer, db.ForeignKey('bike_types.id'), nullable=False)
#
# # The Shops database model
# class Shops(db.Model):
#     id = db.Column(db.Integer, primary_key=True)
#     location_name = db.Column(db.String(100), unique=True, nullable=False)
#     address = db.Column(db.String(100), unique=True, nullable=False)
#     contact_number = db.Column(db.String(15), nullable=False)
#     # Relationship to Bikes
#     bikes = db.relationship('Bikes', backref='shop', lazy=True)
#
# # The Repairs database model
# class Repairs(db.Model):
#     id = db.Column(db.Integer, primary_key=True)
#     date_complete = db.Column(db.DateTime, nullable=False, default=datetime.utcnow)
#     description = db.Column(db.String(500), nullable=False)
#     cost = db.Column(db.Float, default=0.0)
#     # Relationship to Bikes
#     bikes = db.relationship('Bikes', backref='shop', lazy=True)
#
# # The Bookings database model
# # (Bookings of a single bike)
# class Bookings(db.Model):
#     id = db.Column(db.Integer, primary_key=True)
#     start_date = db.Column(db.DateTime, nullable=False, default=datetime.utcnow)
#     end_date = db.Column(db.String(500), nullable=False)
#     price = db.Column(db.Float, default=0.0)
#     # Foreign keys
#     bike_id = db.Column(db.Integer, db.ForeignKey('bikes.id'), nullable=False)
#     rental_id = db.Column(db.Integer, db.ForeignKey('rentals.id'), nullable=False)
#
# # The Rentals database model
# # (May consist of several bookings)
# class Rentals(db.Model):
#     id = db.Column(db.Integer, primary_key=True)
#     date = db.Column(db.DateTime, nullable=False, default=datetime.utcnow)
#     total_price = db.Column(db.Float, default=0.0)
#     #barcode = Something for the barcode here ...*
#     # Foreign keys
#     user_id = db.Column(db.Integer, db.ForeignKey('users.id'), nullable=False)
#     # Relationship to Bookings
#     bookings = db.relationship('Bookings', backref='rental', lazy=True)
