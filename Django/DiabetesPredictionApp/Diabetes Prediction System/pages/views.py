from django.shortcuts import render,redirect

import numpy as np
import pandas as pd
import seaborn as sns
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LogisticRegression
from sklearn.metrics import accuracy_score

# Create your views here.
is_first_time = 0
glob_data={}

def home(request):
    return render(request,"pages/home.html")

def predict(request):

    # if request.method == "GET":
    #     return render(request,"pages/predict.html")

    # elif request.method == "POST":
    # data = pd.read_csv('diabetes.csv')
    # X = data.drop("Outcome",axis = 1)
    # Y = data['Outcome']
    # X_train,X_test,Y_train,Y_test = train_test_split(X,Y,test_size=0.2)
    # model = LogisticRegression()
    # model.fit(X_train,Y_train)

        # Pregnancies = float(request.GET['Pregnancies'])
        # Glucose = float(request.GET['Glucose'])
        # Blood_Pressure = float(request.GET['Blood_Pressure'])
        # Skin_Thickness = float(request.GET['Skin_Thickness'])
        # Insulin = float(request.GET['Insulin'])
        # Diabetes_Pedigree_Function = float(request.GET['Diabetes_Pedigree_Function'])
        # Age = float(request.GET['Age'])
        # data_arr = [Pregnancies,Glucose,Blood_Pressure,Skin_Thickness,Insulin,Diabetes_Pedigree_Function,Age]

        # print(data_arr)
        # prediction = model.predict([data_arr])
        # if pred == [1]:
        #     result = "Postive"
        # else:
        #     result = "Negative"

        # return render(request,"pages/predict.html")


    if request.method == "GET":
        context={}
        return render(request,"pages/predict.html",context) 

    elif request.method == "POST":
        is_first_time = 0

        data = pd.read_csv('media/diabetes.csv')
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
            result = "Postive"
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
            "result":result
        }
        global glob_data
        glob_data = all_data.copy()

        # Printing Data
        # print(glob_data)
        # print("1st")

        return redirect("result")

def result(request):

    # context={}
    # is_first_time = 0
    # if is_first_time == 0:
    #     content = all_data
    #     is_first_time = 1
    # else:
    #     pass

    # Printing Data
    # print(glob_data)
    # print("2st")
    global glob_data
    return render(request,"pages/result.html",glob_data) 
