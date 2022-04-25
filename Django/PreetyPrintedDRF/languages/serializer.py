from rest_framework.decorators import api_view
from rest_framework import serializers
from languages.models import Language

class LanguageSerializer(serializers.ModelSerializer):
    class Meta:
        model = Language
        fields = '__all__'

# class LanguageSerializer(serializers.Serializer):
#     id = serializers.IntegerField(read_only=True)
#     name = serializers.CharField()
#     paradign = serializers.CharField()

#     def create(self,validate_data):
#         return Language.objects.create(**validate_data)

#     def update(self,instance,validate_data):
#         instance.name = validate_data.get('name',instance.name)
#         instance.paradign = validate_data.get('paradign',instance.paradign)
#         instance.save()
#         return instance

