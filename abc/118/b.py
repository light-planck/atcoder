n, m = map(int, input().split())

cnt = [0] * m
for _ in range(n):
    a = list(map(int, input().split()))
    for ai in a[1:]:
        cnt[ai - 1] += 1

ans = 0
for x in cnt:
    if x == n:
        ans += 1

print(ans)