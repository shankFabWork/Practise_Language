from rest_framework import serializers
from flight_app.models import Flight,Passenger,Reservation
import re
class ReservationSerializer(serializers.ModelSerializer):
    class Meta:
        model = Reservation
        fields = "__all__"

def isValidCitis(data):
    if data['departureCity'] == data['arrivalCity']:
        raise serializers.ValidationError("departureCity & arrivalCity can not be same")
    return data

class FlightSerializer(serializers.ModelSerializer):
    reservation = ReservationSerializer(read_only=True,many=True)
    class Meta:
        model = Flight
        fields = "__all__"
        validators=[isValidCitis]

    def validate_flightNumber(self,flightNumber):
        if(re.match("^[a-zA-Z0-9]*$",flightNumber) == None):
            raise serializers.ValidationError("string can only contains alphabets or numerical symbols")
        return flightNumber

    def validate(self,data):
        if data['flightNumber'] == data['operatingAirlines']:
            raise serializers.ValidationError("flightNumber & operatingAirlines can not be same")
        return data

class PassengerSerializer(serializers.ModelSerializer):
    # reservation = ReservationSerializer(read_only=True,many=True)
    class Meta:
        model = Passenger
        fields = "__all__"



