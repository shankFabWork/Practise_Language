from watchlist_app.models import Movie
from watchlist_app.ClassBasedView.serializers import MovieSerializer
from rest_framework.response import Response
# from rest_framework.decorators import api_view
from rest_framework import status
from rest_framework.views import APIView

class MovieListView(APIView):
    def get(self,request):
        all_movie = Movie.objects.all()
        serializer = MovieSerializer(all_movie,many=True)
        return Response(serializer.data)
    def post(self,request):
        serializer = MovieSerializer(data=request.data)
        if serializer.is_valid():
            serializer.save()
            return Response(serializer.data)
        else:
            return Response(serializer.errors)

class MovieDataView(APIView):
    def get(self,request,m_id):
        each_movie = Movie.objects.get(id=m_id)
        serializer = MovieSerializer(each_movie)
        return Response(serializer.data)

    def put(self,request,m_id):
        each_movie = Movie.objects.get(id=m_id)
        serializer = MovieSerializer(each_movie,data=request.data)
        if serializer.is_valid():
            serializer.save()
            return Response(serializer.data)
        else:
            return Response(serializer.errors)

    def delete(self,request,m_id):
        each_movie = Movie.objects.get(id=m_id)
        temp=each_movie
        each_movie.delete()
        data=temp.name+" "+temp.description+" "+str(temp.active)+" "+"Data deleted successfully"
        return Response(data,status=status.HTTP_204_NO_CONTENT)
