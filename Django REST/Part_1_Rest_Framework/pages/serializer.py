from rest_framework import serializers
from pages.models import Employee,Book,Author

# ------------- Serializer ------------- 
# def name_length(val):
#     if len(val) < 2:
#         return serializers.ValidationError("name is too short")
#     else:
#         return val

# class EmployeeSerializer(serializers.Serializer):
#     id = serializers.IntegerField(read_only = True)
#     name = serializers.CharField(validators=[name_length])
#     sal = serializers.IntegerField()

#     desc = serializers.SerializerMethodField()

#     def get_desc(self,obj):
#         return len(obj.name)

#     def create(self,validated_data):
#         return Employee.objects.create(**validated_data)

#     def update(self,instance,validate_data):
#         instance.name = validate_data.get('name',instance.name)
#         instance.sal = validate_data.get('sal',instance.sal)
#         instance.save()
#         return instance

#     def validate_name(self,value):
#         if len(value) < 2:
#             return serializers.ValidationError("name is too short")
#         return value

#     def validator(self,data):
#         if data['name'] == data['desc']:
#             return "name and description should not be same"
#         return data

# ------------- ModelSerializer ------------- 
class EmployeeSerializer(serializers.ModelSerializer):
    class Meta:
        model = Employee
        # fields = "__all__"
        fields = ("id","name","sal")

class BookSerializer(serializers.ModelSerializer):
    class Meta:
        model = Book
        fields = "__all__"

class AuthorSerializer(serializers.ModelSerializer):
    book = BookSerializer(read_only=True,default=None,many=True)
    class Meta:
        model = Author
        fields = "__all__"