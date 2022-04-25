from django.shortcuts import render
from watchlist_app.models import Movie
from django.http import JsonResponse

# Create your views here.

def home(request):
    return render(request,"watchlist_app/home.html")

def movie_list(request):
    all_movie = Movie.objects.all()
    print(list(all_movie.values()))
    context={
        'all_movie':list(all_movie.values())
    }
    return render(request,"watchlist_app/movie_list.html",context)
    # return JsonResponse(context)

def movie_data(request,m_id):
    movie_data = Movie.objects.get(id=m_id)
    context={
        'name':movie_data.name,
        'desc':movie_data.description,
        'active':movie_data.active        
    }
    return render(request,"watchlist_app/movie_data.html",context)
