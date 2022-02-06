MOD = 998244353
n = int(input())

m = 1
ans = 0
while True:
    tmp = 0
    
    if n - 9 * m >= 0:
        n -= 9 * m
        tmp = (9 * m) * (9 * m + 1) // 2
        tmp %= MOD
        ans += tmp

    else:
        tmp = n * (n + 1) // 2
        tmp %= MOD
        ans += tmp
        break
    

    m *= 10

ans %= MOD
print(ans)