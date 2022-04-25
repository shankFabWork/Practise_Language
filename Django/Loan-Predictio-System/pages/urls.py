from . import views
from django.urls import path

urlpatterns = [
    path('',views.home,name="home"),
    path('predict',views.predict,name="predict"),
    # path('result',views.result,name="result"),
    path('recent_results',views.recent_results,name="recent_results"),
    path('recent_results/<int:pk>',views.each_recent_results,name="recent_results"),
    path('show_pdf/<int:pk>',views.show_pdf,name="show_pdf"),
    path('send_html_to_email/<int:pk>',views.send_html_to_email,name="send_html_to_email"),
]
