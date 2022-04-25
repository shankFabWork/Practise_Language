from django import forms

from django.contrib.auth.forms import UserCreationForm
from django.contrib.auth.models import User

from users.models import Profile
from django.utils.translation import gettext, gettext_lazy as _

# class UserRegistrationForm(UserCreationForm):
#     email=forms.EmailField()
#     widgets={
#         'username' : forms.TextInput(attrs={'class':'form-control','placeholder': 'Name', 'style': 'width: 300px;'}),
#         'email' : forms.EmailField(attrs={'class':'form-control','placeholder' :'Email', 'style': 'width: 300px;'}),
#         'password1' : forms.TextInput(label=("Password"), strip=False,widget=forms.PasswordInput(attrs={'autocomplete': 'current-password','class':'form-control'})),
#         'password2' : forms.TextInput(label=("Password"), strip=False,widget=forms.PasswordInput(attrs={'autocomplete': 'current-password','class':'form-control'})),
#     }
#     class Meta:
#         model=User
#         fields=('username','email','password1','password2')

class UserRegistrationForm(UserCreationForm):    
    # password1=forms.CharField(label="Password",widget=forms.PasswordInput(attrs={'class':'form-control'}))
    # password2=forms.CharField(label="Confirm Password (again)",widget=forms.PasswordInput(attrs={'class':'form-control'}))
    class Meta:
        model=User
        fields= ['username','email','password1','password2']

        
        labels= {'email':'Email'}
        widgets={
            'username':forms.TextInput(attrs={'class':'form-control', 'style': 'width: 300px;'}),
            'email':forms.TextInput(attrs={'class':'form-control'}),
        }


        # username = UsernameField(widget=forms.TextInput(attrs={'class':'form-control','autofocus': True}))



 



class UserUpdateForm(forms.ModelForm):
    email=forms.EmailField()
    class Meta:
        model=User
        fields=['username','email']

class ProfielUpdateForm(forms.ModelForm):
    class Meta:
        model=Profile
        fields=['front','back','about','phone_no']

