from django.shortcuts import render

from flight_app.models import Flight,Passenger,Reservation
from flight_app.serializers import FlightSerializer,PassengerSerializer,ReservationSerializer
from rest_framework import viewsets,status
from rest_framework.decorators import api_view

# @api_view(['GET','POST'])
# def find_flight(request):
#     flights = Flight.objects.filter(
#         departureCity=request.data['departureCity'],
#         arrivalCity=request.data['arrivalCity'],
#         dateOfDeparture=request.data['dateOfDeparture']
#     )
#     serializer = FlightSerializer(flights,many=True)
#     return Response(serializer.data)

# @api_view(['GET','POST'])
# def find_flight(request):

#     if request.method =='POST':
#         students = Student.objects.filter(departureCity=departureCity,arrivalCity=arrivalCity,dateOfDeparture=dateOfDeparture)
#         serializer=StudentSerializer(students,many=True)
#         return Response(serializer.data)

#     elif request.method == 'POST':
#         serializer = StudentSerializer(data=request.data)
#         if serializer.is_valid():
#             serializer.save()
#             return Response(serializer.data,status=status.HTTP_201_CREATED)
#         return Response(serializer.errors,status=status.HTTP_400_BAD_REQUEST)

from rest_framework.response import Response

@api_view(['POST'])
def find_flight(request):
    flights = Flight.objects.filter(
        departureCity=request.data['departureCity'],
        arrivalCity=request.data['arrivalCity'],
        dateOfDeparture=request.data['dateOfDeparture']
    )
    serializer = FlightSerializer(flights,many = True)
    return Response(serializer.data)


# flightNumber
# operatingAirlines
# departureCity
# arrivalCity
# dateOfDeparture
# estimatedTimeOfDeparture

# firstName 
# lastName 
# middleName 
# email 
# phone 

@api_view(['POST'])
def save_reservation(request):
    flight = Flight.objects.get(id=request.data['flightNumber'])

    passenger = Passenger()
    passenger.firstName = request.data['firstName']
    passenger.lastName = request.data['lastName']
    passenger.middleName = request.data['middleName']
    passenger.email = request.data['email']
    passenger.phone = request.data['phone']
    passenger.save()

    reservation = Reservation()
    reservation.flight = flight
    reservation.passenger = passenger
    reservation.save()

    # print(request.data['val'])

    return Response(status=status.HTTP_201_CREATED)

from rest_framework.permissions import IsAuthenticated
class FlightAV(viewsets.ModelViewSet):
    queryset = Flight.objects.all()
    serializer_class = FlightSerializer
    permission_classes = [IsAuthenticated]


class PassengerAV(viewsets.ModelViewSet):
    queryset = Passenger.objects.all()
    serializer_class = PassengerSerializer

class ReservationAV(viewsets.ModelViewSet):
    queryset = Reservation.objects.all()
    serializer_class = ReservationSerializer