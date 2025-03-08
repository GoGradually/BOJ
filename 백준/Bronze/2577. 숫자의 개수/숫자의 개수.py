a = int(input())
b = int(input())
c = int(input())

cal = a * b * c

cal_list = list(str(cal))

for i in range(10):
    count = cal_list.count(str(i))
    print(count)
