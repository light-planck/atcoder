n = int(input())
a = list(map(int, input().split()))

x = [0] * n
for i in range(n):
    if i % 2 == 0:
        x[0] += a[i]
    else:
        x[0] -= a[i]

for i in range(n - 1):
    x[i + 1] = 2 * a[i] - x[i]

print(*x)