a = int(input())

numAppear = [0 for i in range(10)]

while a != 0:
    numAppear[a % 10] += 1
    a = a // 10

sum = numAppear[6] + numAppear[9]
if sum % 2 == 1:
    numAppear[6] = sum // 2 + 1
    numAppear[9] = sum // 2
else:
    numAppear[6] = sum // 2
    numAppear[9] = sum // 2

print(max(numAppear))
