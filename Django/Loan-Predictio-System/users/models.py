from django.db import models
from django.contrib.auth.models import User
from PIL import Image
# import Image

# Create your models here.
class Profile(models.Model):
    user=models.OneToOneField(User,on_delete=models.CASCADE)

    isTrained = models.BooleanField(default=False)

    about=models.CharField(max_length=100,null=True,blank=True)
    phone_no=models.CharField(max_length=100,null=True,blank=True)

    front=models.ImageField(default="profile_img/front.jpg",upload_to='profile_img/front_pics')
    back=models.ImageField(default="profile_img/back.jpg",upload_to='profile_img/back_pics')

