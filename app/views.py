from flask import render_template
from app import app

@app.route('/')
def index():
    return render_template("home.html")


@app.route('/browse')
def browse():
    return render_template("browse.html") # this is for the shop page
