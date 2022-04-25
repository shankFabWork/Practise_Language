from django.shortcuts import render,redirect
from .forms import userForm
from .models import ImageModel,EmployeeData,NewsData
from django.core.paginator import Paginator
from django.core.mail import send_mail,EmailMultiAlternatives


def For_Loop_Implementation(request):
    data={
        'work':[1,2,3,4,5],
        'student':[
            {'name':'shank','age':20},
            {'name':'gagan','age':24},
            {'name':'pankaj','age':27},
            {'name':'rajan','age':18},
        ],
        'country_name':'INDIA'
    }
    return render(request,'For_Loop_Implementation.html',data)


# Ways to find "Dynamic Page"
# Slug , int ,str
# Slug -> takes "-" connecting words
def Dynamic_Page(request,userid):
    content={'userid':userid}
    return render(request,'pages_app/Dynamic_Page.html',content)

# Page App Content

def index(request):
    return render(request,'pages_app/index.html')

def portfolio_details(request):
    return render(request,'pages_app/portfolio_details.html')

def inner_page(request):
    return render(request,'pages_app/inner_page.html')
  
def Form_Implementation(request):
    # username = int(request.GET['username'])
    # password = int(request.GET['password'])
    if request.method == 'POST':
        username = request.POST.get('username')
        password = request.POST.get('password')
        # print(username+" "+password)
        context={'username':username,'password':password}
        print(username+" "+password)
        
        #Redirect Ways

        # return render(request,'practise/Form_Thank_U_Page.html',context)

        url="/Form_Thank_U_Page/?username={}&password={}".format(username,password)
        return redirect(url)

        # return redirect('Form_Thank_U_Page')
        
    if request.method == 'GET':
        # context={'username':'','password':''}
        context={}
        
    return render(request,'practise/Form_Implementation.html',context)

def Form_Thank_U_Page(request):
    username = request.GET.get('username')
    password = request.GET.get('password')
    context={'username':username,'password':password}
    return render(request,"practise/Form_Thank_U_Page.html",context)

def DjangoForm(request):
    uf = userForm()
    context={'uf':uf}
    return render(request,"practise/DjangoForm.html",context)

def CalculatorField(request):
    if request.method == "GET":
        context={}
    else:
        num1 = int(request.POST["num1"])
        num2 = int(request.POST["num2"])
        operator = request.POST["operator"]
        msg=""
        val=""
        if operator == "+":
            val = (num1+num2)
        if operator == "-":
            val = (num1-num2)
        if operator == "/":
            try:
                val = (num1/num2)
            except ZeroDivisionError:
                msg="you can not divide a number by 0"
        if operator == "*":
            val = (num1*num2)
        if operator == "%":
            val = (num1%num2)
        context={'val':val,'msg':msg}
    return render(request,"practise/CalculatorField.html",context)


def EvenOddForm(request):
    if request.method == "GET":
        context={}
    else:
        data = int(request.POST["data"])       
        if(data%2 == 0):
            msg="Number is Even"
        else:
            msg="Number is Odd"
        context={'msg':msg}
    return render(request,"practise/EvenOddForm.html",context)

def MarkSheet(request):
    if request.method == 'GET':
        context={}
    else:
        num1 = eval(request.POST['num1'])
        num2 = eval(request.POST['num2'])
        num3 = eval(request.POST['num3'])
        num4 = eval(request.POST['num4'])
        num5 = eval(request.POST['num5'])
        tot_marks = num1+num2+num3+num4+num5
        percentage = tot_marks/500*100
        div=""
        if percentage >= 60:
            div="First Div"
        elif percentage >= 48:
            div="Second Div"
        elif percentage >= 35:
            div="Third Div"
        else:
            div="Fail"
        context={
            'tot_marks':tot_marks,
            'percentage':percentage,
            'div':div
        }
    return render(request,"practise/MarkSheet.html",context)

def AlertBox(request):
    show_msg = False
    msg=""
    msg_type=""
    context={}
    if request.method == 'GET':
        pass
    else:
        data=request.POST['data']
        if data == "":
            msg = "Please Enter Something Inside the Field"
            msg_type="error"
            show_msg = True
        else:
            msg="Form Submitted Successfully"
            msg_type="success"
            show_msg = True
        context={'show_msg':show_msg,'msg_type':msg_type,'msg':msg}
    return render(request,"practise/AlertBox.html",context)

def CarouselDynamic(request):
        #     {
        #         'image_link':'https://cdn.pixabay.com/photo/2014/11/13/06/12/boy-529067_960_720.jpg',
        #         'heading':'Los Angeles',
        #         'description':'LA is always so much fun!'
        #     },
        #     {
        #         'image_link':'https://cdn.pixabay.com/photo/2015/03/26/09/41/chain-690088_960_720.jpg',
        #         'heading':'New York',
        #         'description':'We love the Big Apple!'
        #     },
        #     {
        #         'image_link':'https://images.unsplash.com/photo-1488272690691-2636704d6000?ixid=MnwxMjA3fDB8MHxwaG90by1wYWdlfHx8fGVufDB8fHx8&ixlib=rb-1.2.1&auto=format&fit=crop&w=867&q=80',
        #         'heading':'Los Angeles',
        #         'description':'LA is always so much fun!'
        #     },
        #     {
        #         'image_link':'https://images.unsplash.com/photo-1519819286236-0b3c6506e475?ixid=MnwxMjA3fDB8MHxwaG90by1wYWdlfHx8fGVufDB8fHx8&ixlib=rb-1.2.1&auto=format&fit=crop&w=726&q=80',
        #         'heading':'New York',
        #         'description':'We love the Big Apple!'
        #     },
        #     {
        #         'image_link':'    https://images.unsplash.com/photo-1526498460520-4c246339dccb?ixlib=rb-1.2.1&ixid=MnwxMjA3fDB8MHxwaG90by1wYWdlfHx8fGVufDB8fHx8&auto=format&fit=crop&w=870&q=80',
        #         'heading':'New York',
        #         'description':'We love the Big Apple!'
        #     },
        # ]    
        
    context={
        'image_arr':ImageModel.objects.all().order_by('ImageTitle')
        # 'image_arr':ImageModel.objects.all().order_by('-ImageTitle')[:2]
    }
    return render(request,'practise/CarouselDynamic.html',context)

def MarqueStartStop(request):
    context={
    'new_arr':NewsData.objects.all()
    }
    return render(request,'practise/MarqueStartStop.html',context)

def NewDetails(request,slug):
    context={
        'data':NewsData.objects.get(news_slug=slug)
    }
    return render(request,'practise/NewDetails.html',context)

def FilterOptionsWithPaginator(request):

    if request.method == "GET":
        val = request.GET.get("SearchData")
        if val != None:
            data = NewsData.objects.filter(name__icontains=val)
            context={
                "new_arr":data
            }
            return render(request,'practise/FilterOptionsWithPaginator.html',context)
        else:
            AllObjects = NewsData.objects.all()
            paginator=Paginator(AllObjects,2)
            page_number=request.GET.get("page")
            PageLimitedData=paginator.get_page(page_number)
            total_pages=PageLimitedData.paginator.num_pages
            context={
                "new_arr":PageLimitedData,
                "last_page":total_pages,
                "my_paginator":[i+1 for i in range(total_pages)]
            }
            return render(request,'practise/FilterOptionsWithPaginator.html',context)

def FormDataStore(request):
    if request.method == 'GET':
        context = {}
    else:
        name=request.POST.get('name')
        age=request.POST.get('age')
        ed = EmployeeData(name=name,age=age)
        ed.save()
        msg="Data Suceessfully Saved"
        context = {
            'name':name,
            'age':age,
            'msg':msg
        }

        # 1st Way [ we can not use html here]
        # send_mail(
        #     'Django Practise SMTP SHANK King Mail Sucessfullt Send',
        #     'Here is the message.',
        #     'sharmashankfab@gmail.com',
        #     ['www.shashanksharma8@gmail.com'],
        #     fail_silently=False,
        # )

        # 2st Way [ we not use html here]
        subject, from_email, to = 'hello practising django', 'sharmashankfab@gmail.com', 'www.shashanksharma8@gmail.com'
        text_content = 'I cam use html over here'
        html_content = '<p>This is an <strong>important</strong> <h1 style="color:red">message<h1></p>'
        msg = EmailMultiAlternatives(subject, text_content, from_email, [to])
        msg.attach_alternative(html_content, "text/html")
        msg.send()

    return render(request,'practise/FormDataStore.html',context)

def ShowAllEmployeeData(request):
    all_data=EmployeeData.objects.all()
    context={
        'emp_data':all_data
    }
    return render(request,'practise/ShowAllEmployeeData.html',context)