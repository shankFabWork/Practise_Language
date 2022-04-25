from django.urls import path
from . import views
from django.conf import settings
from django.conf.urls.static import static
urlpatterns=[
    path('',views.index,name='index'),
    path('inner_page',views.inner_page,name='inner_page'),
    path('portfolio_details',views.portfolio_details,name='portfolio_details'),
    # For Practise
    path('Dynamic_Page/<slug:userid>',views.Dynamic_Page,name='Dynamic_Page'),
    path('For_Loop_Implementation/',views.For_Loop_Implementation,name='For_Loop_Implementation'),
    path('Form_Implementation/',views.Form_Implementation,name='Form_Implementation'),
    path('Form_Thank_U_Page/',views.Form_Thank_U_Page,name='Form_Thank_U_Page'),
    path('DjangoForm/',views.DjangoForm,name='DjangoForm'),
    path('CalculatorField/',views.CalculatorField,name='CalculatorField'),
    path('EvenOddForm/',views.EvenOddForm,name='EvenOddForm'),
    path('MarkSheet/',views.MarkSheet,name='MarkSheet'),
    path('AlertBox/',views.AlertBox,name='AlertBox'),
    path('CarouselDynamic/',views.CarouselDynamic,name='CarouselDynamic'),
    path('MarqueStartStop/',views.MarqueStartStop,name='MarqueStartStop'),
    path('NewDetails/<slug>',views.NewDetails,name='NewDetails'),
    path('FilterOptionsWithPaginator/',views.FilterOptionsWithPaginator,name='FilterOptionsWithPaginator'),
    path('FormDataStore/',views.FormDataStore,name='FormDataStore'),
    path('ShowAllEmployeeData/',views.ShowAllEmployeeData,name='ShowAllEmployeeData'),
]

if settings.DEBUG:
    urlpatterns+=static(settings.MEDIA_URL,document_root=settings.MEDIA_ROOT)