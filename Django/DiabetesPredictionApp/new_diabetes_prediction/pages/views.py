from django.shortcuts import render,redirect
from.models import Diabetes
from django.contrib.auth.models import User
from django.contrib.auth.decorators import login_required
from django.views.decorators.csrf import csrf_exempt

import numpy as np
import pandas as pd
import seaborn as sns
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LogisticRegression
from sklearn.metrics import accuracy_score

from django.shortcuts import render
from io import BytesIO
from django.http import HttpResponse
from django.template.loader import get_template
from django.views import View
from xhtml2pdf import pisa

import datetime
import re

from django.shortcuts import render
from django.http import JsonResponse
from django.template.loader import get_template
from django.core.mail import EmailMessage
from django.conf import settings

# Create your views here.
glob_data={}

def home(request):
    return render(request,"pages/home.html")

@csrf_exempt
@login_required
def predict(request):
    if request.method == "GET":
        context={}
        return render(request,"pages/predict.html",context) 

    elif request.method == "POST":

        data = pd.read_csv('static/diabetes.csv')
        X = data.drop("Outcome",axis = 1)
        Y = data['Outcome']

        X_train,X_test,Y_train,Y_test = train_test_split(X,Y,test_size=0.2)
        model = LogisticRegression()
        model.fit(X_train,Y_train)

        Pregnancies = float(request.POST['Pregnancies'])
        Glucose = float(request.POST['Glucose'])
        Blood_Pressure = float(request.POST['Blood_Pressure'])
        Skin_Thickness = float(request.POST['Skin_Thickness'])
        Insulin = float(request.POST['Insulin'])
        Bmi_val = float(request.POST['Bmi_val'])
        Diabetes_Pedigree_Function = float(request.POST['Diabetes_Pedigree_Function'])
        Age = float(request.POST['Age'])

        data_arr = [Pregnancies,Glucose,Blood_Pressure,Skin_Thickness,Insulin,Bmi_val,Diabetes_Pedigree_Function,Age]
        prediction = model.predict([data_arr])

        if prediction == [1]:
            result = "Positive"
        else:
            result = "Negative"

        all_data = {
            "Pregnancies":Pregnancies,
            "Glucose":Glucose,
            "Blood_Pressure":Blood_Pressure,
            "Skin_Thickness":Skin_Thickness,
            "Insulin":Insulin,
            "Bmi_val":Bmi_val,
            "Diabetes_Pedigree_Function":Diabetes_Pedigree_Function,
            "Age":Age,
            "result":result,
            "messages":[
                {"tags":"success","text":"Result Fetched Successfully"}
            ],
            "is_first_time":2
        }
        global glob_data
        glob_data = all_data.copy()

        b = Diabetes.objects.create(
            user=request.user,
            Pregnancies=Pregnancies,
            Glucose=Glucose,
            Blood_Pressure=Blood_Pressure,
            Skin_Thickness=Skin_Thickness,
            Insulin=Insulin,
            Bmi_val=Bmi_val,
            Diabetes_Pedigree_Function=Diabetes_Pedigree_Function,
            Age=Age,
            Result=result
        )
        b.save()

        # user = User.objects.create_user(username="name", email="email@mail.com", password="Pass12345")
        # post_1 = Post(name="testname", email="testemail", gender="Monsieur", number="23233", author=user)

        # Printing Data
        # print(glob_data)
        # print("1st")

    return redirect("result")

@login_required
def result(request):
    global glob_data
    if glob_data["is_first_time"] > 0:
        glob_data["is_first_time"] -= 1
    else:
        pass
    return render(request,"pages/result.html",glob_data) 

@login_required
def recent_results(request):
    arr = Diabetes.objects.filter(user=request.user)
    context={
        "all_results":arr
    }
    for i in arr:
        print(i.Result)
    return render(request,"pages/recent_results.html",context) 

@login_required
def each_recent_results(request,pk):
    arr = Diabetes.objects.filter(user=request.user)
    # data=Question.objects.get(id=id)
    each_result_data=""
    for i in arr:
        # print(i.pk)
        if i.pk == pk:
            each_result_data=i
            break
    # print(pk)
    # print(arr)
    context={
        "each_result_data":each_result_data
    }
    return render(request,"pages/each_recent_results.html",context) 

def render_to_pdf(template_src, context_dict={}):
    template = get_template(template_src)
    html = template.render(context_dict)
    result = BytesIO()
    pdf = pisa.pisaDocument(BytesIO(html.encode("ISO-8859-1")), result)
    if not pdf.err:
     return HttpResponse(result.getvalue(), content_type='application/pdf')
    return None

@login_required
def show_pdf(request,pk):
    arr = Diabetes.objects.filter(user=request.user)
    each_result_data=""
    for i in arr:
        if i.pk == pk:
            each_result_data=i
            break
    context={
        "each_result_data":each_result_data,
        "user":request.user
    }
    pdf = render_to_pdf('dummy_profile.html',context)
    return HttpResponse(pdf,content_type='application/pdf')

def send_html_to_email(request,pk):
    html_tpl_path = 'dummy_profile.html'
    arr = Diabetes.objects.filter(user=request.user)
    each_result_data=""
    for i in arr:
        if i.pk == pk:
            each_result_data=i
            break
    context={
        "each_result_data":each_result_data,
        "user":request.user
    }
    
    email_html_template = get_template(html_tpl_path).render(context)
    receiver_email = request.user.email+""
    # print(request.user.email)
    email_msg = EmailMessage('Welcome from django app', 
                                email_html_template, 
                                settings. APPLICATION_EMAIL,
                                [receiver_email],
                                reply_to=[settings.APPLICATION_EMAIL]
                                )
    # this is the crucial part that sends email as html content but not as a plain text
    email_msg.content_subtype = 'html'
    email_msg.send(fail_silently=False)
    return redirect("recent_results")