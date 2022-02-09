from collections import deque


n, m = map(int, input().split())

g =[[] for _ in range(n)]
for _ in range(m):
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    g[a].append(b)
    g[b].append(a)

dist = [-1] * n
dist[0] = 0

que = deque()
que.append(0)

# 部屋iの道しるべがjのときprev[i] = j
marker = [0] * n
while que:
    v = que.popleft()

    for next in g[v]:
        if dist[next] != -1:
            continue
            
        dist[next] = dist[v] + 1
        marker[next] = v + 1
        que.append(next)

if -1 in dist:
    print('No')
else:
    print('Yes')
    
    for i in range(1, n):
        print(marker[i])