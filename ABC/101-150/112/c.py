n = int(input())

x = []
y = []
h = []
for _ in range(n):
    xi, yi, hi = list(map(int, input().split()))
    x.append(xi)
    y.append(yi)
    h.append(hi)

for cx in range(101):
    for cy in range(101):
        ch = 1

        # (x, y)の高さはhだが、中心の高さは1以上なので
        # 高さh = 0のときは無視
        for i in range(n):
            if h[i] > 0:
                ch = h[i] + abs(x[i] - cx) + abs(y[i] - cy)

        ok = True
        for i in range(n):
            if h[i] != max(ch - abs(x[i] - cx) - abs(y[i] - cy), 0):
                ok = False

        if ok:
            print(f'{cx} {cy} {ch}')