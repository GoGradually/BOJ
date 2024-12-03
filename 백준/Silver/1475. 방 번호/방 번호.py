a = int(input())

numAppear = [0 for i in range(10)]

while a != 0:
    numAppear[a % 10] += 1
    a = a // 10

replace = (numAppear[6] + numAppear[9] + 1)//2
numAppear[6] = replace
numAppear[9] = replace

print(max(numAppear))



