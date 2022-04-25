from rest_framework import serializers
from watchlist_app.models import Movie


# class MovieSerializer(serializers.ModelSerializer):
#     name_length = serializers.SerializerMethodField()

#     class Meta:
#         model=WatchList
#          fields=['id','name','description','active']
#          fields=['id','name','description','name_length']
#          fields="__all__"
#          exclude=['active']

class MovieSerializer(serializers.Serializer):
    id = serializers.IntegerField(read_only=True)
    name = serializers.CharField()
    description = serializers.CharField()
    active = serializers.BooleanField()

    def create(self,validated_data):
        return Movie.objects.create(**validated_data)

    def update(self,instance,validated_data):
        instance.name = validated_data.get('name',instance.name)
        instance.description = validated_data.get('description',instance.description)
        instance.active = validated_data.get('active',instance.active)
        instance.save()
        return instance
        
    def get_name_length(self,obj):
        return len(obj.name)
    
    def validate_name(self,value):
        if len(value) < 2:
            raise serializers.ValidationError("Name is too short")
        else:
            return value

    def validate(self,data):
        if data['name'] == data['description']:
            raise serializers.ValidationError("name and desciption can not be same")        
        else:
            return data

        
