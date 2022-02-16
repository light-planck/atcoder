import sys
sys.setrecursionlimit(10 ** 6)
from functools import lru_cache

MOD = 998244353


@lru_cache
def dfs(x):
    if x <= 4:
        return x
    
    y = x // 2
    z = (x + 2 - 1) // 2
    return dfs(y) * dfs(z) % MOD


x = int(input())
ans = dfs(x)
print(ans)