n = int(input())
h = [0] + list(map(int, input().split())) + [0]

cnt = 0
for i in range(n):
    if h[i] < h[i + 1]:
        cnt += h[i + 1] - h[i]

print(cnt)