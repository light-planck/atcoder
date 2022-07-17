import sys
input = sys.stdin.readline
sys.setrecursionlimit(10 ** 6)


def dfs(v, p, cnt):
    if p != -1:
        cnt[v] += cnt[p]
    
    for next_v in g[v]:
        if next_v == p:
            continue
        
        dfs(next_v, v, cnt)


n, q = map(int, input().split())

g = [[] for _ in range(n)]
for _ in range(n - 1):
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    
    g[a].append(b)
    g[b].append(a)

cnt = [0] * n
for _ in range(q):
    p, x = map(int, input().split())
    p -= 1
    
    cnt[p] += x

dfs(0, -1, cnt)
print(*cnt)