from flask import render_template
from app import app
from .forms import NewUserForm, LoginForm

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
