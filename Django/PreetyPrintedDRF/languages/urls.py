from django.urls import path
from languages.views import listingAV,detailsAV
from languages import views

urlpatterns=[
    path('',views.home,name='home'),
    # path('language_list/',views.listing,name='listing'),
    # path('language_list/<int:l_id>',views.details,name='details'),
    path('language_list/',listingAV.as_view(),name='listing'),
    path('language_list/<int:l_id>',detailsAV.as_view(),name='details'),
]