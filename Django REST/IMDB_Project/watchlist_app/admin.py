from django.contrib import admin
from watchlist_app.models import WatchList,StreamPlatform,Review
# Register your models here.

admin.site.register(WatchList)
admin.site.register(StreamPlatform)
admin.site.register(Review)

# @admin.register
# class ReviewAdmin(admin.ModelAdmin):
#     list_display = ['id','rating','description','admin','created','update','watchlist'] 
