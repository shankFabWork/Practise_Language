from fastapi import FastAPI
from enum import Enum

app = FastAPI()

class Available_Cuisines(str,Enum):
    indian = "indian"
    american = "american"
    italian = "italian"
    
food_items = {
    'indian' : [ "Samosa", "Dosa" ],
    'american' : [ "Hot Dog", "Apple Pie"],
    'italian' : [ "Ravioli", "Pizza"]
}

valid_cuisine = food_items.keys()
content = "-".join(list(valid_cuisine))
@app.get("/get_items/{cuisine}")
async def get_items(cuisine:Available_Cuisines):
    # return food_items.get(cuisine)
    # if cuisine not in valid_cuisine:
    #     return f"supported food items are {content}"
    return food_items.get(cuisine)

coupon_code = {
    1: '10%',
    2: '20%',
    3: '30%'
}

@app.get("/get_coupon/{code}")
async def get_coupon(code: int):
    return { 'discount_amount': coupon_code.get(code) }