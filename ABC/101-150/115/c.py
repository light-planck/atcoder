n, k = map(int, input().split())

h = []
for _ in range(n):
    x = int(input())
    h.append(x)

h.sort()
min_d = 1e9
for i in range(n - k + 1):
    min_d = min(min_d, h[i + k - 1] - h[i])
print(min_d)