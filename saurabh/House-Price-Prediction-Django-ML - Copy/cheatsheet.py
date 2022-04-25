conda deactivate

pip install virtualenv
virtualenv env
.\env\Scripts\activate

pip install flask
pip install flask-wtf
pip install numpy
pip install pandas
pip install sklearn
cd server
python server.py
