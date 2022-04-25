from django.urls import path
from . import views

urlpatterns=[
    path('register/',views.register,name='register'),
    path('profile/',views.profile,name='profile'),
    path('update/',views.update,name='update'),
    path('all_user/',views.all_user,name='all_user'),
]