n = int(input())

sum = 0
max_p = 0
for _ in range(n):
    p = int(input())
    max_p = max(max_p, p)
    sum += p

ans = sum - max_p + max_p // 2
print(ans)