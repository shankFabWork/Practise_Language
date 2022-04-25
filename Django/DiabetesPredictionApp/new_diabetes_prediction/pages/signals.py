from django.db.models.signals import post_save
from django.dispatch import receiver
from users.models import Diabetes
from django.contrib.auth.models import User

@receiver(post_save,sender=User)
def create_diabetes(sender,instance,created,**kwargs):
    if created:
        Diabetes.objects.create(user=instance).save()
        
