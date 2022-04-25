from django.urls import path
from watchlist_app.ClassBasedView.views import MovieListView,MovieDataView

urlpatterns=[
    # path("",views.home,name="home"),
    path("movie_list/", MovieListView.as_view(),name="MovieListView"),
    path("movie_list/<int:m_id>",MovieDataView.as_view(),name="MovieDataView"),
]