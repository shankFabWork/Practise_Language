from django.db import models
from django.contrib.auth.models import User

# Create your models here.
class Diabetes(models.Model):
    user=models.ForeignKey(User,on_delete=models.CASCADE)

    Pregnancies=models.IntegerField(null=True,blank=True)
    Glucose=models.IntegerField(null=True,blank=True)
    Blood_Pressure=models.IntegerField(null=True,blank=True)
    Skin_Thickness=models.IntegerField(null=True,blank=True)
    Insulin=models.IntegerField(null=True,blank=True)
    Bmi_val=models.IntegerField(null=True,blank=True)
    Diabetes_Pedigree_Function=models.IntegerField(null=True,blank=True)
    Age=models.IntegerField(null=True,blank=True)

    Result=models.CharField(max_length=100,null=True,blank=True)
    pub_date=models.DateTimeField(auto_now_add=True)
