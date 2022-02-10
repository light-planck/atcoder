n, x, y = map(int, input().split())
x -= 1
y -= 1

cnt = [0] * n
for i in range(n):
    for j in range(i + 1, n):
        dist = abs(j - y) + abs(i - x) + 1
        dist = min(dist, j - i)
        
        cnt[dist] += 1

for k in range(1, n):
    print(cnt[k])