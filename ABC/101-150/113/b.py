n = int(input())
t, a = map(int, input().split())
h = list(map(int, input().split()))

diff = []
for hi in h:
    avg = t - hi * 0.006
    diff.append(abs(avg - a))

ans = diff.index(min(diff)) + 1
print(ans)