from collections import deque

MAX_N = 10 ** 6

a, n = map(int, input().split())

dist = [-1] * MAX_N
dist[1] = 0

que = deque()
que.append(1)

while len(que):
    x = que.popleft()

    # 操作1
    if x * a < MAX_N and dist[x * a] == -1:
        que.append(x * a)
        dist[x * a] = dist[x] + 1

    # 操作2
    if x >= 10 and x % 10 != 0:
        s = str(x)
        s = s[-1] + s[:-1]
        y = int(s)

        if y < MAX_N and dist[y] == -1:
            que.append(y)
            dist[y] = dist[x] + 1

print(dist[n])