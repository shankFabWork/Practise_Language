from django.contrib import admin
from pages_app.models import NewsData,EmployeeData,ImageModel

admin.site.register(ImageModel)
admin.site.register(NewsData)
admin.site.register(EmployeeData)
