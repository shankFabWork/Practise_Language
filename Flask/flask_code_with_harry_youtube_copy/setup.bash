conda deactivate

pip install virtualenv
virtualenv env

# It will run only in PowerShell 
# [ First run Powershell admin and make it available for all]
Set-ExecutionPolicy Unrestricted

.\env\Scripts\activate

python app.py

pip install flask
pip install Flask-SQLAlchemy

python 
from app import db
db.create_all()
exit()