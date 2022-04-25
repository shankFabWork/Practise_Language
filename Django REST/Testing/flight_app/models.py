from django.db import models

#Token Configuration
from django.db.models.signals import post_save
from django.dispatch import receiver
from rest_framework.authtoken.models import Token
from django.conf import settings

class Flight(models.Model):
    flightNumber=models.CharField(max_length=10,null=True)
    operatingAirlines=models.CharField(max_length=20)
    departureCity=models.CharField(max_length=20)
    arrivalCity=models.CharField(max_length=20)
    dateOfDeparture=models.DateField()
    estimatedTimeOfDeparture=models.TimeField()

    # def __str__(self):
    #     return self.

class Passenger(models.Model):
    firstName = models.CharField(max_length=20)
    lastName = models.CharField(max_length=20)
    middleName = models.CharField(max_length=20,blank=True,null=True,default="")
    email = models.CharField(max_length=30)
    phone = models.CharField(max_length=10)

class Reservation(models.Model):
    flight = models.ForeignKey(Flight,on_delete=models.CASCADE,related_name="reservation")
    passenger = models.OneToOneField(Passenger,on_delete=models.CASCADE,related_name="reservation")
