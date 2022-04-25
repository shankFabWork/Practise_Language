from . import views
from django.urls import path

urlpatterns = [
    path('',views.home,name="home"),
    path('predict',views.predict,name="predict"),
    path('result',views.result,name="result"),
]
