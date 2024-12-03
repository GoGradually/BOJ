a = int(input())
b = int(input())
c = int(input())

product = a * b * c

numAppear = [0 for i in range(10)]

while product != 0:
    numAppear[product%10] += 1
    product = product // 10

for i in range(10):
    print(numAppear[i])