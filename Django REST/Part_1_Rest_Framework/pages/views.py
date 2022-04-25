from django.shortcuts import render
from django.http import JsonResponse

from pages.models import Employee,Book,Author
from pages.serializer import EmployeeSerializer,BookSerializer,AuthorSerializer

# from rest_framework.decorators import api_view
# from rest_framework.views import APIView
from rest_framework import mixins,generics
from rest_framework import status
from rest_framework.response import Response

def home(request):
    # return render(request,'pages/home.html')
    
    # obj = {
    #     'name':'shank',
    #     'age':20
    # }

    all_emp = Employee.objects.all()
    obj = { 
        "Employee":list(all_emp.values('name','sal'))
    }
    return JsonResponse(obj)

# ------------ Function Based View [FBV] ------------
# @api_view(['GET','POST'])
# def emp_list(request):
#     if request.method == 'GET':
#         data = Employee.objects.all()
#         serializer = EmployeeSerializer(data,many = True)
#         return Response(serializer.data)

#     if request.method == 'POST':
#         serializer = EmployeeSerializer(data = request.data)
#         if serializer.is_valid():
#             serializer.save()
#             return Response(serializer.data,status=status.HTTP_201_CREATED)
#         return Response(serializer.error,status=status.HTTP_400_BAD_REQUEST)

# @api_view(['GET','PUT','DELETE'])
# def emp_detail(request,pk):
#     if request.method == 'GET':
#         try:
#             data = Employee.objects.get(id=pk)
#         except:
#             return Response("id do not exists",status=status.HTTP_404_NOT_FOUND)
#         serializer = EmployeeSerializer(data)
#         return Response(serializer.data)

#     if request.method == 'PUT':
#         data = Employee.objects.get(id=pk)
#         serializer = EmployeeSerializer(data,data=request.data)
#         if serializer.is_valid():
#             serializer.save()
#             return Response(serializer.data)
#         return Response(serializer.error,status=status.HTTP_404_NOT_FOUND)

#     if request.method == 'DELETE':
#         data = Employee.objects.get(id=pk)
#         data.delete()
#         return Response("deleted successfully",status=status.HTTP_204_NO_CONTENT)


# ------------ Class Based View [CBV] ------------
# class emp_list(APIView):
#     def get(self,request):
#         data = Employee.objects.all()
#         serializer = EmployeeSerializer(data,many = True)
#         return Response(serializer.data)

#     def post(self,request):
#         serializer = EmployeeSerializer(data = request.data)
#         if serializer.is_valid():
#             serializer.save()
#             return Response(serializer.data,status=status.HTTP_201_CREATED)
#         return Response(serializer.error,status=status.HTTP_400_BAD_REQUEST)

# class emp_detail(APIView):
#     def get(self,request,pk):
#         try:
#             data = Employee.objects.get(id=pk)
#         except:
#             return Response("id do not exists",status=status.HTTP_404_NOT_FOUND)
#         serializer = EmployeeSerializer(data)
#         return Response(serializer.data)

#     def put(self,request,pk):
#         data = Employee.objects.get(id=pk)
#         serializer = EmployeeSerializer(data,data=request.data)
#         if serializer.is_valid():
#             serializer.save()
#             return Response(serializer.data)
#         return Response(serializer.error,status=status.HTTP_404_NOT_FOUND)

#     def delete(self,request,pk):
#         data = Employee.objects.get(id=pk)
#         data.delete()
#         return Response("deleted successfully",status=status.HTTP_204_NO_CONTENT)

# ------------ Using Mixins ------------
# class emp_list(mixins.ListModelMixin,mixins.CreateModelMixin,generics.GenericAPIView):
#     queryset = Employee.objects.all()
#     serializer_class = EmployeeSerializer

#     def get(self,request):
#         return self.list(request)

#     def post(self,request):
#         return self.create(request)

# class emp_detail(mixins.UpdateModelMixin,mixins.DestroyModelMixin,mixins.RetrieveModelMixin,generics.GenericAPIView):
#     queryset = Employee.objects.all()
#     serializer_class = EmployeeSerializer

#     def get(self,request,pk):
#         return self.retrieve(request,pk)

#     def put(self,request,pk):
#         return self.update(request,pk)

#     def delete(self,request,pk):
#         return self.destroy(request,pk)

# ------------ Using Generic View ------------
# class emp_list(generics.ListCreateAPIView):
#     queryset = Employee.objects.all()
#     serializer_class = EmployeeSerializer

# class emp_detail(generics.RetrieveUpdateDestroyAPIView):
#     queryset = Employee.objects.all()
#     serializer_class = EmployeeSerializer

# ------------ Using Viewsets ------------
from rest_framework import viewsets
from rest_framework.pagination import LimitOffsetPagination,PageNumberPagination

class emp_pagination(PageNumberPagination):
    page_size = 1

# ------------ Gloabal Authentication ------------
# from rest_framework.authentication import BasicAuthentication
# from rest_framework.permissions import IsAuthenticated,DjangoModelPermissions

class emp_viewset(viewsets.ModelViewSet):
    queryset = Employee.objects.all()
    serializer_class = EmployeeSerializer
    pagination_class = PageNumberPagination
    # pagination_class = LimitOffsetPagination
    pagination_class = emp_pagination
    # authentication_classes = [BasicAuthentication]
    # permission_classes = [IsAuthenticated,DjangoModelPermissions]


from rest_framework import generics

class book_list_generic_view(generics.ListCreateAPIView):
    queryset = Book.objects.all()
    serializer_class = BookSerializer

class book_detail_generic_view(generics.RetrieveUpdateDestroyAPIView):
    queryset = Book.objects.all()
    serializer_class = BookSerializer

class author_list_generic_view(generics.ListCreateAPIView):
    queryset = Author.objects.all()
    serializer_class = AuthorSerializer

class author_detail_generic_view(generics.RetrieveUpdateDestroyAPIView):
    queryset = Author.objects.all()
    serializer_class = AuthorSerializer

# ------------ Pagination ------------
# from rest_framework.pagination import LimitOffsetPagination,PageNumberPagination

# class emp_pagination(LimitOffsetPagination):
#     page_size = 2

# class LargeResultsSetPagination(PageNumberPagination):
#     page_size = 1
#     page_size_query_param = 'page_size'

# class BillingRecordsView(generics.ListAPIView):
#     queryset = Billing.objects.all()
#     serializer_class = BillingRecordsSerializer
#     pagination_class = LargeResultsSetPagination