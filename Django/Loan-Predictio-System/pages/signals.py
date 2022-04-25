from django.db.models.signals import post_save
from django.dispatch import receiver
from users.models import LoanInformation
from django.contrib.auth.models import User

@receiver(post_save,sender=User)
def create_loaninformation(sender,instance,created,**kwargs):
    if created:
        LoanInformation.objects.create(user=instance).save()
        
