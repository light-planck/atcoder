n = int(input())
h = list(map(int, input().split()))

now = 0
for hi in h:
    if now < hi:
        now = hi
    else:
        break

print(now)