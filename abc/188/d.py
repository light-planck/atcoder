n, c = map(int, input().split())

event = []
for _ in range(n):
    a, b, cost = map(int, input().split())
    event.append([a, cost])
    event.append([b + 1, -cost])
event.sort()

prev = 0
sum = 0
ans = 0
for day, cost in event:
    ans += (day - prev) * min(c, sum)

    sum += cost
    prev = day

print(ans)