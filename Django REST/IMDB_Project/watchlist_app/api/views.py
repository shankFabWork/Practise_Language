from watchlist_app.models import WatchList,StreamPlatform,Review
from watchlist_app.api.serializers import (
    WatchListSerializer,StreamPlatformSerializer,ReviewSerializer
)
from rest_framework.response import Response
# from rest_framework.decorators import api_view
from rest_framework import status
from rest_framework.views import APIView    
from rest_framework import mixins,generics,status
from rest_framework import viewsets 

class WatchListAV(APIView):
    def get(self,request):
        all_movie = WatchList.objects.all()
        serializer = WatchListSerializer(all_movie,many=True)
        return Response(serializer.data)
    def post(self,request):
        serializer = WatchListSerializer(data=request.data)
        if serializer.is_valid():
            serializer.save()
            return Response(serializer.data)
        else:
            return Response(serializer.errors)

class WatchDetailView(APIView):
    def get(self,request,m_id):
        each_movie = WatchList.objects.get(id=m_id)
        serializer = WatchListSerializer(each_movie)
        return Response(serializer.data)

    def put(self,request,m_id):
        each_movie = WatchList.objects.get(id=m_id)
        serializer = WatchListSerializer(each_movie,data=request.data)
        if serializer.is_valid():
            serializer.save()
            return Response(serializer.data)
        else:
            return Response(serializer.errors)

    def delete(self,request,m_id):
        each_movie = WatchList.objects.get(id=m_id)
        temp=each_movie
        each_movie.delete()
        data=temp.name+" "+temp.description+" "+str(temp.active)+" "+"Data deleted successfully"
        return Response(data,status=status.HTTP_204_NO_CONTENT)

#working
# class StreamPlatformListAV(APIView):
#     def get(self,request):
#         all_movie = StreamPlatform.objects.all()
#         serializer = StreamPlatformSerializer(all_movie,many=True)
#         return Response(serializer.data)

#     def post(self,request):
#         serializer = StreamPlatformSerializer(data=request.data)    
#         if serializer.is_valid():
#             serializer.save()
#         else:
#             # raise serializers.ValidationError("data is not valid")
#             return Response(serializer.errors)
#         return Response(serializer.data)

class StreamPlatformListVS(viewsets.ViewSet):
    """
    A simple ViewSet for listing or retrieving users.
    """
    def list(self, request):
        queryset = StreamPlatform.objects.all()
        serializer = StreamPlatformSerializer(queryset, many=True)
        return Response(serializer.data)

    def retrieve(self, request, pk=None):
        queryset = StreamPlatform.objects.all()
        watchlist = get_object_or_404(queryset, pk=pk)
        serializer = StreamPlatformSerializer(StreamPlatform)
        return Response(serializer.data)

class StreamPlatformDetialAV(APIView):
    def get(self,request,m_id):
        each_movie = StreamPlatform.objects.get(id=m_id)
        serializer = StreamPlatformSerializer(each_movie)
        return Response(serializer.data)    

    def put(self,request,m_id):
        each_movie = StreamPlatform.objects.get(id=m_id)
        serializer = StreamPlatformSerializer(each_movie,data=request.data)
        if serializer.is_valid():
            serializer.save()
        else:
            # raise serializers.ValidationError("data is not valid")
            return Response(serializer.errors) 
        return Response(serializer.data)

    def delete(self,request,m_id):
        each_movie = StreamPlatform.objects.get(id=m_id)
        each_movie.delete()
        return Response("Deleted Sucessfully",status=status.HTTP_204_NO_CONTENT)

# class ReviewList(mixins.CreateModelMixin,mixins.ListModelMixin,generics.GenericAPIView):
#     queryset = Review.objects.all()
#     serializer_class = ReviewSerializer

#     def get(self,request,*args,**kwargs):
#         return self.list(request,*args,**kwargs)

#     def post(self,request,*args,**kwargs):
#         return self.create(request,*args,**kwargs)

# class ReviewDetail(mixins.RetrieveModelMixin,generics.GenericAPIView):
#     queryset = Review.objects.all()
#     serializer_class = ReviewSerializer

#     def get(self,request,*args,**kwargs):
#         return self.retrieve(request,*args,**kwargs)



class ReviewCreate(generics.CreateAPIView):
    # queryset = Review.objects.all()
    serializer_class = ReviewSerializer

    def perform_create(self,serializer):
        pk = self.kwargs.get('pk')
        watchlist = WatchList.objects.get(pk=pk)
        serializer.save(watchlist=watchlist)

class ReviewList(generics.ListAPIView):
    # queryset = Review.objects.all()
    serializer_class = ReviewSerializer

    def get_queryset(self):
        pk = self.kwargs['pk']
        return Review.objects.filter(watchlist=pk)

class ReviewDetail(generics.RetrieveUpdateDestroyAPIView):
    queryset = Review.objects.all()
    serializer_class = ReviewSerializer
    