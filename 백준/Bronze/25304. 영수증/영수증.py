TotalBill = int(input())
ProductType = int(input())
TotalPrice = 0

for i in range(ProductType):
    ProductPrice, ProductQuantity = map(int, input().split())
    Price = ProductPrice * ProductQuantity
    TotalPrice += Price

if TotalBill == TotalPrice:
    print("Yes")
else:
    print("No")
