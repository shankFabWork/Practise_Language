from django.db import models
from tinymce.models import HTMLField
from autoslug import AutoSlugField


# Create your models here.
class ImageModel(models.Model):
    ImageLink = models.CharField(max_length=1000)
    ImageTitle = models.CharField(max_length=50)
    ImageDesc = models.TextField()


class NewsData(models.Model):
    name=models.CharField(max_length=100)
    description=HTMLField()
    news_slug=AutoSlugField(populate_from="name",unique=True,default=None)


class EmployeeData(models.Model):
    name=models.CharField(max_length=100)
    age=models.IntegerField()
    employeeImg=models.FileField(upload_to="emp/",max_length=250,default=None,null=True)



