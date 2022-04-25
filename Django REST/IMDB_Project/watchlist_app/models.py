from django.db import models
from django.core.validators import MinValueValidator,MaxValueValidator

# class Movie(models.Model):
#     name = models.CharField(max_length=50)
#     description = models.CharField(max_length=50)
#     active = models.BooleanField(default=True)
#     def __str__(self):
#         return self.name

class StreamPlatform(models.Model):
    name=models.CharField(max_length = 30)
    about=models.CharField(max_length=150)
    website=models.URLField(max_length=100)

    def __str__(self):
        return self.name

class WatchList(models.Model):
    title = models.CharField(max_length=100)
    storyline = models.CharField(max_length=100)
    active = models.BooleanField(default=True)
    created = models.DateTimeField(auto_now_add=True)
    platform = models.ForeignKey(
        StreamPlatform,
        on_delete=models.CASCADE,
        default=None,
        # related_name='watchlist'
    )

    def __str__(self):
        return self.title

class Review(models.Model):
    rating = models.PositiveIntegerField(validators=[MinValueValidator(1),MaxValueValidator(5)])
    description = models.CharField(max_length=200,null=True)
    active = models.BooleanField(default = True)
    created = models.DateTimeField(auto_now_add = True)
    update = models.DateTimeField(auto_now = True)
    watchlist = models.ForeignKey(
        WatchList,
        on_delete = models.CASCADE,
        default = None,
        related_name='reviews'
    )

    def __str__(self):
        return self.watchlist.title+" --> "+str(self.rating)