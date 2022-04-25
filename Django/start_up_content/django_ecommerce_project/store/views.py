from django.shortcuts import render
from store.models import Order
# Create your views here.

def store(request):
    # print(Order.objects.filter(transaction_id="2312").first().customer.email)
    # print(Order.objects.filter(transaction_id="2312").first().orderitem_set.all().first())
    # for i in Order.objects.filter(transaction_id="2312").first().orderitem_set.all():
    #     print(i.product.name)
    #     print(i.product.price)
    #     print(i.quantity)
    #     print()
    # print(Order.objects.filter(transaction_id="2312").first().shippingaddress_set.all())

    # print(Order.objects.get_or_create(customer=request.user.customer, complete=False))
    # order,created = (Order.objects.get_or_create(customer=request.user.customer, complete=False))
    # print(order)
    # for key, value in Order.objects.get_or_create(customer=request.user.customer, complete=False.first().items():
    #     print(key, value)
    # for i in Order.objects.filter(transaction_id="2312").first().orderitem_set.all():
    #     print(i.product.name)
    #     print(i.product.price)
    #     print(i.quantity)
    #     print(i.get_total)  
    #     print()

    context = {}
    return render(request, 'store/store.html',context)

def cart(request):
    context = {}
    print()
    return render(request, 'store/cart.html',context)

def checkout(request):
    context = {}
    return render(request, 'store/checkout.html',context)