n, m = map(int, input().split())
x = list(map(int, input().split()))
x.sort()

dx = []
for i in range(m - 1):
    d = x[i + 1] - x[i]
    dx.append(d)

dx.sort(reverse = True)
ans = x[m - 1] - x[0]

if n <= len(dx):
    for i in range(n - 1):
        ans -= dx[i]
else:
    ans = 0

print(ans)