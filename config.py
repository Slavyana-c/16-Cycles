WTF_CSRF_ENABLED = False
SECRET_KEY = '39994353502789d8701e9ff62e8f86d1'


import os


basedir = os.path.abspath(os.path.dirname(__file__))
SQLALCHEMY_DATABASE_URI = 'sqlite:///' + os.path.join(basedir, 'app.db')
SQLALCHEMY_TRACK_MODIFICATIONS = True

