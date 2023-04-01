import math


n, m = map(int, input().split())
inf = 10**24 + 1
ans = inf
limit = int(math.sqrt(m))

for a in range(1, limit+1):
    b = (m+a-1) // a
    
    if a < 1 or a > n: continue
    if b < 1 or b > n: continue
    if a*b < m: continue

    ans = min(ans, a*b)

if ans == inf:
    ans = -1
    
print(ans)