from django.urls import path
from . import views

urlpatterns=[
    path("",views.home,name="home"),
    path("movie_list/",views.movie_list,name="movie_list"),
    path("movie_data/<int:m_id>",views.movie_data,name="movie_data"),
]