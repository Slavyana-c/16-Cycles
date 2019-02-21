from flask import render_template
from app import app
from .forms import NewUserForm, LoginForm, SelectDates

@app.route('/')
def home():
    return render_template("home.html")

@app.route('/about')
def about():
    return render_template("about.html") # redirect to the about page

@app.route('/browse')
def browse():
    form = SelectDates();
    return render_template("browse.html", form=form) # redirect to the bike search page

@app.route('/bikePage')
def bikePage():
    form = SelectDates();
    return render_template("bikePage.html", form=form) # redirect to the bike search page

@app.route('/account')
def account():
    return render_template("account.html") # redirect to the account page

@app.route('/sign_up', methods=['GET', 'POST'])
def sign_up():
	form = NewUserForm()
	return render_template("sign_up.html", form=form)


@app.route('/login', methods=['GET', 'POST'])
def login():
	form = LoginForm()
	return render_template("login.html", form=form)
