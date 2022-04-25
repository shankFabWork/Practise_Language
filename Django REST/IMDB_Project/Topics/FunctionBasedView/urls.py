from django.urls import path
from watchlist_app.FunctionBasedView import views

urlpatterns=[
    # path("",views.home,name="home"),
    path("movie_list/", views.movie_list,name="movie_list"),
    path("movie_list/<int:m_id>",views.each_movie,name="each_movie"),
]