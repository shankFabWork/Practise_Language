from django.urls import path
from watchlist_app.api.views import (
    WatchListAV,WatchDetailView,
    StreamPlatformListAV,StreamPlatformDetialAV,
    ReviewList,ReviewDetail
)
# ,StreamPlatformAV,StreamPlatformDetailAV

urlpatterns=[
    # path("",views.home,name="home"),
    path("watchlist/", WatchListAV.as_view(),name="WatchListAV"),
    path("watchlist/<int:m_id>",WatchDetailView.as_view(),name="WatchDetailView"),
    path("streamplatform/", StreamPlatformListAV.as_view(),name="StreamPlatformListAV"),
    path("streamplatform/<int:m_id>",StreamPlatformDetialAV.as_view(),name="StreamPlatformDetialAV"),
    path("review/", ReviewList.as_view(),name="review-list"),
    path("review/<int:pk>", ReviewDetail.as_view(),name="review-detail"),
]