n = int(input())

x = []
y = []

for _ in range(n):
    xi, yi = map(int, input().split())
    x.append(xi)
    y.append(yi)

max_d = 0
for i in range(n):
    for j in range(n):
        dist = (x[i] - x[j]) ** 2 + (y[i] - y[j]) ** 2
        dist = dist ** 0.5
        max_d = max(max_d, dist)

print(max_d)