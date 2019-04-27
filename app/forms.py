from flask_wtf import FlaskForm
from wtforms import StringField, PasswordField, BooleanField, SubmitField, RadioField
from wtforms.validators import DataRequired, Length, Email, EqualTo, ValidationError, Regexp, NumberRange
from wtforms.fields.html5 import DateField, IntegerField
from app.models import Users
import datetime
from datetime import timedelta

class NewUserForm(FlaskForm):

	email = StringField('Email',
						validators=[DataRequired(), Email()])
	contact_number = StringField('Contact Number',
						validators=[DataRequired()])
	password = PasswordField('Password',
							validators=[DataRequired(), Length(min=5, max=25)])
	confirm_password = PasswordField('Confirm Password',
									validators=[DataRequired(),
												EqualTo('password')])
	submit = SubmitField('Sign Up')


	def validate_email(self, email):
		user = Users.query.filter_by(email=email.data).first()
		if user:
			raise ValidationError('That email address is already linked to '
								  'an account.\nPlease log in or choose a '
								  'different one')


class LoginForm(FlaskForm):

	email = StringField('Email',
						validators=[DataRequired(), Email()])
	password = PasswordField('Password',
							validators=[DataRequired(), Length(min=5, max=25)])
	remember = BooleanField('Remember Me')
	submit = SubmitField('Sign In')


class PasswordChangeForm(FlaskForm):

	email = StringField('Email',
						validators=[DataRequired(), Email()])
	password = PasswordField('Password',
							validators=[DataRequired(), Length(min=5, max=25)])
	repeatPassword = PasswordField('Repeat Password',
							validators=[DataRequired(), Length(min=5, max=25)])
	submit = SubmitField('Submit')


class RequestPasswordForm(FlaskForm):

	email = StringField('Email',
						validators=[DataRequired(), Email()])
	submit = SubmitField('Request Password Reset')

	def validate_email(self, email):
		user = Users.query.filter_by(email=email.data).first()
		if user is None:
			raise ValidationError('No account with that email exists')


class NewPasswordForm(FlaskForm):

	password = PasswordField('Password',
							  validators=[DataRequired(), Length(min=5, max=25)])
	confirm_password = PasswordField('Confirm Password',
									validators=[DataRequired(),
												EqualTo('password')])
	submit = SubmitField('Change Password')


# form in the newTask.html
class SelectDates(FlaskForm):
	start_date = DateField('Rent Start Date', validators=[DataRequired()], default=datetime.datetime.now())
	end_date = DateField('Rent End Date', validators=[DataRequired()], default=datetime.datetime.now()+timedelta(days=1))
	submit = SubmitField('Search')
	# VALIDATION DOESN'T WORK :(
	def validate_date(form, end_date, start_date):
	    if end_date.data < start_date.data:
	        raise ValidationError('End date must be later than start date')

class AppliedFilters(FlaskForm):
	# shopChoice = RadioField('Extend Date', validators=[DataRequired()])
	shopChoice   = RadioField('Shop', choices=[(1,'University'),(2,'Town'),(3,'Headingley')])
	typeChoice   = RadioField('Type', choices=[('Road','Road'),('Mountain','Mountain'),('Hybrid','Hybrid'),('Electric','Electric')])
	ageChoice    = RadioField('Age', choices=[('Adult','Adult'),('Child','Child')])
	colourChoice = RadioField('Colour', choices=[('Blue','Blue'),('Red','Red'),('Grey','Grey'),('Black','Black'),('White','White'),('Brown','Brown')])
	brandChoice  = RadioField('Brand', choices=[('Apollo','Apollo'),('Boardman','Boardman'),('Carrera','Carrera'),('Elswick','Elswick'),('Gtech','Gtech'),('Pendleton','Pendleton'),('Raleigh','Raleigh'),('Voodoo','Voodoo')])
	submit = SubmitField('Apply Filters')

class DisableFilters(FlaskForm):
	# shopChoice = RadioField('Extend Date', validators=[DataRequired()])
	# Shop   = RadioField('Shop', choices=[('shop','shop')], default='shop')
	# Type   = RadioField('Type', choices=[('type','type')])
	# Age    = RadioField('Age', choices=[('age','age')])
	# Colour = RadioField('Colour', choices=[('colour','colour')])
	# Brand  = RadioField('Brand', choices=[('brand','brand')])
	Shop = SubmitField('X')
	Type = SubmitField('X')
	Age = SubmitField('X')
	Colour = SubmitField('X')
	Brand = SubmitField('X')

class ExtendDate(FlaskForm):
	new_end_date = DateField('Extend Date', validators=[DataRequired()])
	submit = SubmitField('Update Date')

class PaymentForm(FlaskForm):
	cardNumber = StringField('Card Number', validators=[DataRequired(), Regexp("\d+", flags=0, message=""), Length(min=8, max=16, message="Field must be between 8 and 16 digits. Please try again")])
	cvv = StringField('CVV', validators=[DataRequired(), Regexp("\d{3}", flags=0, message="Field must be 3 characters long. Please try again"), Length(max=3, message="Field must be 3 characters long. Please try again")])
	expDate = StringField('Expiry Date', validators=[DataRequired(), Regexp("\d\d\/\d\d", flags=0, message="Date needs to be of the form mm/yy")])
	email = StringField('Email Address', validators=[DataRequired()])
	submit = SubmitField('Submit')

class RentButton(FlaskForm):
	submit = SubmitField('RENT', validators=[DataRequired()])
