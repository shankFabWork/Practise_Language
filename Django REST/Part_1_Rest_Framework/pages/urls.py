from django.urls import path,include
from pages import views
from rest_framework.routers import DefaultRouter

router = DefaultRouter()
router.register('emp_list',views.emp_viewset)

urlpatterns = [
    # path('emp/',views.home,name='home'),

    path('',include(router.urls)),

    # ------------ Function Based View [FBV] ------------
    # path('emp_list/',views.emp_list,name='emp_list'),
    # path('emp_list/<int:pk>',views.emp_detail,name='emp_detail'),

    # ------------ Class Based View [CBV] ------------
    # path('emp_list/',views.emp_list.as_view(),name='emp_list'),
    # path('emp_list/<int:pk>',views.emp_detail.as_view(),name='emp_detail'),

    path('book_list/',views.book_list_generic_view.as_view(),name='book_list'),
    path('book_list/<int:pk>',views.book_detail_generic_view.as_view(),name='book_detail'),

    path('author_list/',views.author_list_generic_view.as_view(),name='author_list'),
    path('author_list/<int:pk>',views.author_detail_generic_view.as_view(),name='author_detail'),
]