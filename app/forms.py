from flask_wtf import FlaskForm
from wtforms import StringField, PasswordField, SubmitField
from wtforms.validators import DataRequired, Length, Email, EqualTo, ValidationError





class NewUserForm(FlaskForm):
	username = StringField('Username',
							validators=[DataRequired(), Length(min=5, max=20)])
	email = StringField('Email',
						validators=[DataRequired(), Email()])
	password = PasswordField('Password',
							validators=[DataRequired(), Length(min=5, max=25)])
	confirm_password = PasswordField('Confirm Password',
									validators=[DataRequired(),
												EqualTo('password')])
	submit = SubmitField('Sign Up')

	# def validate_username(self, username):
	# 	user = User.query.filter_by(username=username.data).first()
	# 	if user:
	# 		raise ValidationError('That username is taken. Please choose a '
	# 							  'different one.')
	#
	# def validate_email(self, email):
	# 	user = User.query.filter_by(email=email.data).first()
	# 	if user:
	# 		raise ValidationError('That email address is already linked to '
	# 							  'an account.\nPlease log in or choose a '
	# 							  'different one')


class LoginForm(FlaskForm):

	email = StringField('Email',
						validators=[DataRequired(), Email()])
	password = PasswordField('Password',
							validators=[DataRequired(), Length(min=5, max=25)])
	submit = SubmitField('Sign In')