from django.urls import path
from watchlist_app.api.views import (
    WatchListAV,WatchDetailView,
    StreamPlatformListVS,StreamPlatformDetialAV,
    ReviewList,ReviewDetail,ReviewCreate
)

from rest_framework.routers import DefaultRouter

router = DefaultRouter()
router.register('stream', StreamPlatformListVS.as_view(), basename='stream')

# router_list = StreamPlatformListVS.as_view({'get': 'list'})
# router_detail = StreamPlatformListVS.as_view({'get': 'retrieve'})
# urlpatterns = router.urls

# ,StreamPlatformAV,StreamPlatformDetailAV

urlpatterns=[
    # path("",views.home,name="home"),
    path("watchlist/", WatchListAV.as_view(),name="WatchListAV"),
    path("watchlist/<int:m_id>",WatchDetailView.as_view(),name="WatchDetailView"),
    
    # path("streamplatform/", StreamPlatformListAV.as_view(),name="StreamPlatformListAV"),
    # path("streamplatform/<int:m_id>",StreamPlatformDetialAV.as_view(),name="StreamPlatformDetialAV"),
    
    # path("review/", ReviewList.as_view(),name="review-list"),
    # path("review/<int:pk>", ReviewDetail.as_view(),name="review-detail"),
    path('',include(router.urls)),
    
    path("watchlist/<int:pk>/review_create", ReviewCreate.as_view(),name="StreamPlatformListAV"), 
    path("watchlist/<int:pk>/review", ReviewList.as_view(),name="StreamPlatformListAV"), 
    path("watchlist/review/<int:m_id>",ReviewDetail.as_view(),name="StreamPlatformDetialAV"),
]
