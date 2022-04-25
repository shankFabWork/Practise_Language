from django.db import models

class Employee(models.Model):
    # id = models.IntegerField(primary_key = True)
    name = models.CharField(max_length = 100)
    sal = models.DecimalField(max_digits = 10,decimal_places = 3)
    
    def __str__(self):
        return str(self.id)+" |  "+self.name+" | "+str(self.sal)

class Author(models.Model):
    first_name = models.CharField(max_length=20)
    last_name = models.CharField(max_length=20)

    def __str__(self):
        return str(self.first_name+" "+self.last_name)

class Book(models.Model):
    title = models.CharField(max_length=20)
    rating = models.CharField(max_length=20)
    author = models.ForeignKey(
        Author,
        on_delete=models.CASCADE,
        related_name="book",
        default = None
    )

    def __str__(self):
        return self.title+" - "+str(self.rating)
