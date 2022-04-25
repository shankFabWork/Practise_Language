from django import forms

class userForm(forms.Form):
    num1 = forms.CharField(label="User Name",required=False,widget=forms.TextInput(attrs={'class':'form-control'}))
    num2 = forms.CharField(label="Password",required=False,widget=forms.TextInput(attrs={'class':'form-control'}))
    email_field = forms.EmailField(required=True)
