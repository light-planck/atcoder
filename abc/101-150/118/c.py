import math

n = int(input())
a = list(map(int, input().split()))

ans = a[0]
for ai in a:
    ans = math.gcd(ans, ai)

print(ans)