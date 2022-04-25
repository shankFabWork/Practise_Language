from django.shortcuts import render
# from rest_framework.decorators import api_view
from rest_framework.views import APIView
from rest_framework.response import Response
from languages.models import Language
from languages.serializer import LanguageSerializer
from rest_framework import status

def home(request):
    return render(request,"languages/index.html")

# @api_view(['GET','POST'])
# def listing(request):
#     if request.method == 'GET':
#         all_language = Language.objects.all()
#         serializer = LanguageSerializer(all_language,many=True)
#         return Response(serializer.data)
#     if request.method == 'POST':
#         serializer = LanguageSerializer(data=request.data)
#         if serializer.is_valid():
#             serializer.save()
#             return Response(serializer.data)
#         else:
#             return Response(serializer.errors)


# @api_view(['GET','PUT','DELETE'])
# def details(request,l_id):
#     if request.method == 'GET':
#         each_language = Language.objects.get(id=l_id)
#         serializer = LanguageSerializer(each_language)
#         return Response(serializer.data)
#     if request.method == 'PUT':
#         each_language = Language.objects.get(id=l_id)
#         serializer = LanguageSerializer(each_language,data=request.data)
#         if serializer.is_valid():
#             serializer.save()
#             return Response(serializer.data)
#         else:
#             return Response(serializer.errors)
#     if request.method == 'DELETE':
#         each_language = Language.objects.get(id=l_id)
#         each_language.delete()
#         return Response("deleted successfully",status=status.HTTP_204_NO_CONTENT)


class listingAV(APIView):
    def get(self,request):
        all_language = Language.objects.all()
        serializer = LanguageSerializer(all_language,many=True)
        return Response(serializer.data)
    def post(self,request):
        serializer = LanguageSerializer(data=request.data)
        if serializer.is_valid():
            serializer.save()
            return Response(serializer.data)
        else:
            return Response(serializer.errors)


class detailsAV(APIView):
    def get(self,request,l_id):
        each_language = Language.objects.get(id=l_id)
        serializer = LanguageSerializer(each_language)
        return Response(serializer.data)
    def put(self,request,l_id):
        each_language = Language.objects.get(id=l_id)
        serializer = LanguageSerializer(each_language,data=request.data)
        if serializer.is_valid():
            serializer.save()
            return Response(serializer.data)
        else:
            return Response(serializer.errors)
    def delete(self,request,l_id):
        each_language = Language.objects.get(id=l_id)
        each_language.delete()
        return Response("deleted successfully",status=status.HTTP_204_NO_CONTENT)
