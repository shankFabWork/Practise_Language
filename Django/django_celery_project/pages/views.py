from django.shortcuts import render
from .tasks import test_func

def home(request):
    test_func.delay()
    return render(request,"pages/home.html")