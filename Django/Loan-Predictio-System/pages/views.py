from django.shortcuts import render,redirect
from .models import LoanInformation
from users.models import Profile
from django.contrib.auth.models import User
from django.contrib.auth.decorators import login_required
from django.views.decorators.csrf import csrf_exempt

import numpy as np
import pandas as pd
import seaborn as sns
from sklearn.model_selection import train_test_split
from sklearn.metrics import accuracy_score
from sklearn.linear_model import LogisticRegression
from sklearn.preprocessing import LabelEncoder

from django.http import HttpResponse
from django.template.loader import get_template
from django.views import View

# Used for working with PDF
from io import BytesIO
from xhtml2pdf import pisa

import datetime
import re

from django.http import JsonResponse
from django.template.loader import get_template
from django.core.mail import EmailMessage
from django.conf import settings


# loading library
# from sklearn.externals import joblib
import joblib
import os

# Create your views here.
# glob_data={}

def home(request):
    return render(request,"pages/home.html")

@csrf_exempt
@login_required
def predict(request):
    if request.method == "GET":
        context={}
        return render(request,"pages/predict.html",context) 

    elif request.method == "POST":

        # Reading All the Data from the form
        Gender=float(request.POST['Gender'])
        Married=float(request.POST['Married'])
        Dependents=float(request.POST['Dependents'])
        Education=float(request.POST['Education'])
        Self_Employed=float(request.POST['Self_Employed'])
        ApplicantIncome=float(request.POST['ApplicantIncome'])
        CoapplicantIncome=float(request.POST['CoapplicantIncome'])
        LoanAmount=float(request.POST['LoanAmount'])
        Loan_Amount_Term=float(request.POST['Loan_Amount_Term'])
        Credit_History=float(request.POST['Credit_History'])
        Property_Area=float(request.POST['Property_Area'])

        if os.path.exists("model_jlib") != True or Profile.objects.filter(user=request.user).first().isTrained == False:

            loan_train = pd.read_csv("static/dataset//train.csv")
            loan_test = pd.read_csv("static/dataset//test.csv")

            loan_train_cc = loan_train.copy()

            loan_train['Credit_History'].fillna(method='ffill', inplace=True)

            median_loan = loan_train['Loan_Amount_Term'].median()
            loan_train['Loan_Amount_Term'].fillna((median_loan), inplace=True)

            median_loan_amount = loan_train['LoanAmount'].median()
            loan_train['LoanAmount'].fillna((median_loan_amount), inplace=True)

            loan_train['Self_Employed'].fillna('No', inplace=True)

            loan_train['Dependents'].fillna(0, inplace=True)

            loan_train['Married'].fillna('Yes', inplace=True)

            # fill with mode
            loan_train['Gender'].fillna('Male', inplace=True)

            # fill in credit history
            loan_test['Credit_History'].fillna(method='ffill', inplace=True)

            # fill in loan amount term
            median_loan_test = loan_test['Loan_Amount_Term'].median()
            loan_test['Loan_Amount_Term'].fillna((median_loan_test), inplace=True)

            # fill in loan amount
            median_loan_amount_test = loan_test['LoanAmount'].median()
            loan_test['LoanAmount'].fillna((median_loan_amount_test), inplace=True)

            # fill in self employed
            loan_test['Self_Employed'].fillna('No', inplace=True)

            # fill in dependents
            loan_test['Dependents'].fillna(0, inplace=True)

            # fill in gender
            loan_test['Gender'].fillna('Male', inplace=True)

            #first identify all categorical columns & pass into a variable
            objectlist_train = loan_train.select_dtypes(include = "object").columns


            # Then Label Encoding for object to numeric conversion
            le = LabelEncoder()

            for feature in objectlist_train:
                loan_train[feature] = le.fit_transform(loan_train[feature].astype(str))

            # Now, repeat the same process to encode the test data
            objectlist_test = loan_test.select_dtypes(include='object').columns

            for feature in objectlist_test:
                loan_test[feature] = le.fit_transform(loan_test[feature].astype(str))

            x = loan_train.iloc[:,1:].drop('Loan_Status', axis=1) # drop loan_status column because that is what we are predicting
            y = loan_train['Loan_Status']
            train_x, test_x, train_y, test_y = train_test_split(x, y, test_size=0.30, random_state=0)

            lr = LogisticRegression()
            lr.fit(train_x, train_y)
            # pred_l = logmodel.predict(X_test)
            # acc_l

            """Train Test Split"""
            
            joblib.dump(lr,'model_jlib')
            p_obj = Profile.objects.get(user=request.user)
            p_obj.isTrained = True
            p_obj.save()

            # Profile.objects.filter(user=request.user).first().isTrained = False
            # Profile.objects.filter(user=request.user).first().isTrained.save()
        else:
            #training the support Vector Macine model
            # load saved model
            # print("------------------------")
            # print("yes model_jlib exists")
            # print(os.path.exists("model_jlib"))

            lr = joblib.load('model_jlib')

        data_arr = [
            Gender, Married, Dependents, Education,
            Self_Employed, ApplicantIncome, CoapplicantIncome, LoanAmount,
            Loan_Amount_Term, Credit_History, Property_Area
        ]

        print()
        print(data_arr)
        print("here")
        print(lr.predict([[1,1,0,1,1,2609,3449.0,165.0,180.0,0.0,0]]))

        prediction = lr.predict([data_arr])

        if prediction[0] == 0:
            result = 0
        else:
            result = 1

        all_data = {
            "Gender":Gender,
            "Married":Married,
            "Dependents":Dependents,
            "Education":Education,
            "Self_Employed":Self_Employed,
            "ApplicantIncome":ApplicantIncome,
            "CoapplicantIncome":CoapplicantIncome,
            "LoanAmount":LoanAmount,
            "Loan_Amount_Term":Loan_Amount_Term,
            "Credit_History":Credit_History,
            "Property_Area":Property_Area,

            "result":result,
            "is_first_time":1
        }
        print(all_data)

        b = LoanInformation.objects.create(
            user=request.user,

            Gender=Gender,
            Married=Married,
            Dependents=Dependents,
            Education=Education,
            Self_Employed=Self_Employed,
            ApplicantIncome=ApplicantIncome,
            CoapplicantIncome=CoapplicantIncome,
            LoanAmount=LoanAmount,
            Loan_Amount_Term=Loan_Amount_Term,
            Credit_History=Credit_History,
            Property_Area=Property_Area,

            Result=result
        )
        b.save()
    return render(request,"pages/result.html",all_data) 

@login_required
def recent_results(request):
    arr = LoanInformation.objects.filter(user=request.user)
    receiver_email = request.user.email
    context={
        "all_results":arr,
    }

    return render(request,"pages/recent_results.html",context) 

@login_required
def each_recent_results(request,pk):
    arr = LoanInformation.objects.filter(user=request.user,id=pk).first()
    context={
        "each_result_data":arr
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
    arr = LoanInformation.objects.filter(user=request.user)
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
    arr = LoanInformation.objects.filter(user=request.user)
    each_result_data=""
    receiver_email = request.user.email

    for i in arr:
        if i.pk == pk:
            each_result_data=i
            break


    context={
        "each_result_data":each_result_data,
        "user":request.user,
        "is_first_time":1,
        "each_result_data":each_result_data,
        "all_results":arr,
        "messages":[
            {"tags":"success","text":"Sending Loan Report to mail id : {}".format(receiver_email)}
        ],
    }
    
    email_html_template = get_template(html_tpl_path).render(context)
    # print(request.user.email)
    email_msg = EmailMessage('Welcome from Loan Prediction System', 
                                email_html_template, 
                                settings. APPLICATION_EMAIL,
                                [receiver_email],
                                reply_to=[settings.APPLICATION_EMAIL]
                                )
    # this is the crucial part that sends email as html content but not as a plain text
    email_msg.content_subtype = 'html'
    email_msg.send(fail_silently=False)

    arr = LoanInformation.objects.filter(user=request.user)

    return render(request,"pages/recent_results.html",context) 
