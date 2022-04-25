# write in settings.py file 
CELERY_BROKER_URL = 'redis://127.0.0.1:6379'
CELERY_ACCEPT_CONTENT = ['application/json']
CELERY_RESULT_SERIALIZER = 'json'
CELERY_TASK_SERIALIZER = 'json'
CELERY_TIMEZONE = 'Asia/Kolkata'

# We write this to check the status of all the tasks
# with that you have to install one module i.e. 
pip install django-celery-results
# and mention this inside the installed_app of settings.py file
'django_celery_results',

# and this in settings.py file
CELERY_RESULT_BACKEND = 'django-db'

# write in celery.py file in project 
from __future__ import absolute_import, unicode_literals
import os
from celery import Celery
from django.conf import settings
from celery.schedules import crontab
os.environ.setdefault('DJANGO_SETTINGS_MODULE', 'django_celery_project.settings')
app = Celery('django_celery_project')
# By Default time zone is utc
# we have already mentioned explicitly in settins.py
# about the CELERY_TIMEZONE
app.conf.enable_utc = False
app.conf.update(timezone = 'Asia/Kolkata')
app.config_from_object(settings, namespace='CELERY')
app.autodiscover_tasks()

@app.task(bind=True)
def debug_task(self):
    print(f'Request: {self.request!r}')


# write in tasks.py file in project 
from celery import shared_task

@shared_task(bind=True)
def test_func(self):
    #operations
    for i in range(10):
        print(i)
    return "Done"

# Write in terminal 
celery -A django_celery_project.celery worker --pool=solo -l info

# Write this inside the __init__.py file of the django project
from .celery import app as celery_app
__all__ = ('celery_app',)

# Write this before the return of all function in views.py
test_func.delay()

# ----- CELERY BEAT SET-UP -----
# Mention this inside the installed_app of settings.py file
'django_celery_beat',
# and mention this inside the settings.py file
# CELERY BEAT
CELERY_BEAT_SCHEDULER = 'django_celery_beat.schedulers:DatabaseScheduler'
# Celery beat is used for the periodic command after certain intervel
# Mention this in celery.py file of the project above app.autodiscover_tasks()
app.conf.beat_schedule = {}
# Apply Migrations
python manage.py makemigrations
python manage.py migrate
# Run this in terminal to check the tasks with their status
# you can see this in celery.py file
celery -A django_celery_project beat -l info

# Make sure that your celery server is running
redis-server.exe

# Celery , Celery Beat and Celery Result

# Installtion Guide
pip install django-celery-beat
# install redix in windows/linux
#For linux
# Redis Server Install
sudo apt-get install redis-server
# run redis server
sudo systemctl status redis-server4
# If error
sudo systemctl restart redis-server



pip install celery
python manage.py makemigrations
python manage.py migrate      
pip install redis

# Run server
python manage.py runserver

# You can periodically run this command to backup the crontab into file.
crontab -l > my_crontab.backup

#
celery upgrade 'django_celery_project.settings.py'
