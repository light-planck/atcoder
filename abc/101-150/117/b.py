n = int(input())
l = list(map(int, input().split()))

max_l = 0
for li in l:
    max_l = max(max_l, li)

sum = 0
for li in l:
    sum += li

if max_l < sum - max_l:
    print("Yes")
else:
    print("No")