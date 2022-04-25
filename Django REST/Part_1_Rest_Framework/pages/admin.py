from django.contrib import admin
from pages.models import Employee,Author,Book

admin.site.register(Employee)
admin.site.register(Book)
admin.site.register(Author)

# @admin.register
# class EmployeeAdmin(admin.ModelAdmin):
    # model = Employee
    # fields = "__all__"
    # pass
