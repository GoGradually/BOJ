n = int(input())
arr = list(map(int, input().split()))

x = int(input())

appear = [0 for _ in range(2000001)]
for i in arr:
    appear[i] += 1

ans = 0

for i in arr:
    ans += appear[x - i]

print(ans//2)
