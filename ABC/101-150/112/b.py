n, t = map(int, input().split())

min_c = 1e9
for _ in range(n):
    ci, ti = map(int, input().split())
    if ti <= t:
        min_c = min(min_c, ci)

if min_c == 1e9:
    print("TLE")
else:
    print(min_c)