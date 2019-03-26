from flask_wtf import FlaskForm
from wtforms import StringField, PasswordField, BooleanField, SubmitField
from wtforms.validators import DataRequired, Length, Email, EqualTo, ValidationError, Regexp, NumberRange
from wtforms.fields.html5 import DateField, IntegerField
from app.models import Users

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


# form in the newTask.html
class SelectDates(FlaskForm):
	start_date = DateField('Rent Start Date', validators=[DataRequired()])
	end_date = DateField('Rent End Date', validators=[DataRequired()])
	submit = SubmitField('Select Date')
	print("here")

class ExtendDate(FlaskForm):
	new_end_date = DateField('Extend Date', validators=[DataRequired()])
	submit = SubmitField('Update Date')

class PaymentForm(FlaskForm):
	cardNumber = StringField('Card Number', validators=[DataRequired(), Regexp("\d+", flags=0, message=""), Length(min=8, max=16, message="Field must be between 8 and 16 digits. Please try again")])
	cvv = StringField('CVV', validators=[DataRequired(), Regexp("\d{3}", flags=0, message="Field must be 3 characters long. Please try again"), Length(max=3, message="Field must be 3 characters long. Please try again")])
	expDate = StringField('Expiry Date', validators=[DataRequired(), Regexp("\d\d\/\d\d", flags=0, message="Date needs to be of the form mm/yy")])
	email = StringField('Email Address', validators=[DataRequired()])
	submit = SubmitField('Submit')
