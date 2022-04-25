from django.db import models
from django.contrib.auth.models import User

# Create your models here.
class LoanInformation(models.Model):
    user=models.ForeignKey(User,on_delete=models.CASCADE)

    Gender=models.IntegerField(null=True,blank=True)
    Married=models.IntegerField(null=True,blank=True)
    Dependents=models.IntegerField(null=True,blank=True)
    Education=models.IntegerField(null=True,blank=True)
    Self_Employed=models.IntegerField(null=True,blank=True)
    ApplicantIncome=models.IntegerField(null=True,blank=True)
    CoapplicantIncome=models.IntegerField(null=True,blank=True)
    LoanAmount=models.IntegerField(null=True,blank=True)
    Loan_Amount_Term=models.IntegerField(null=True,blank=True)
    Credit_History=models.IntegerField(null=True,blank=True)
    Property_Area=models.IntegerField(null=True,blank=True)

    Result=models.CharField(max_length=100,null=True,blank=True)
    pub_date=models.DateTimeField(auto_now_add=True)
