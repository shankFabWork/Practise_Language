from django.urls import path,include
from rest_framework.routers import DefaultRouter
from flight_app import views
from rest_framework.authtoken.views import obtain_auth_token  
router = DefaultRouter()
router.register('flight',views.FlightAV)
router.register('passenger',views.PassengerAV)
router.register('reservation',views.ReservationAV)

urlpatterns = [
    path("",include(router.urls)),
    path("find_flight/",views.find_flight),
    path("save_reservation/",views.save_reservation),
    path("api-token-auth/",obtain_auth_token,name="api_token_auth")
]