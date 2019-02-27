from flask import Flask
from flask_sqlalchemy import SQLAlchemy
from flask_migrate import Migrate
from flask_admin import Admin #import for the flask admin page


app = Flask(__name__)
app.config.from_object('config')
db = SQLAlchemy(app)

from flask_login import LoginManager
login_manager = LoginManager(app)
login_manager.login_view='login'
login_manager.login_message_category='info'
#admin
admin = Admin(app,template_mode='bootstrap3')

migrate = Migrate(app, db)

from app import views

migrate = Migrate(app, db)

from app import views, models

