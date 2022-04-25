from watchlist_app.models import Movie
from watchlist_app.FunctionBasedView.serializers import MovieSerializer
from rest_framework.response import Response
from rest_framework.decorators import api_view
from rest_framework import status

@api_view(['GET','POST'])
def movie_list(request):
    if request.method == 'GET':
        all_movie = Movie.objects.all()
        serializer = MovieSerializer(all_movie,many=True)
        return Response(serializer.data)
    if request.method == 'POST':
        serializer = MovieSerializer(data=request.data)
        if serializer.is_valid():
            serializer.save()
            return Response(serializer.data)
        else:
            return Response(serializer.errors)

@api_view(['GET','PUT','DELETE'])
def each_movie(request,m_id):
    if request.method == 'GET':
        try:
            each_movie = Movie.objects.get(id=m_id)
            serializer = MovieSerializer(each_movie)
            return Response(serializer.data)
        except Movie.DoesNotExist:
            return Response({'Error':'Id not found'},status=status.HTTP_400_BAD_REQUEST)
    
    if request.method == 'PUT':
        each_movie = Movie.objects.get(id=m_id)
        serializer = MovieSerializer(each_movie,data=request.data)
        if serializer.is_valid():
            serializer.save()
            return Response(serializer.data)
        else:
            return Response(serializer.errors,status=status.HTTP_400_BAD_REQUEST)

    if request.method == 'DELETE':
        each_movie = Movie.objects.get(id=m_id)
        each_movie.delete()
        data=str(each_movie.name)+" "+str(each_movie.description)+" "+str(each_movie.active)
        return Response("deleted successfully"+" "+data,status=status.HTTP_204_NO_CONTENT)