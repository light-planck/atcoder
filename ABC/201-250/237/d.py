from collections import deque


n = int(input())
s = input()

deq = deque()
deq.append(n)

for i in range(n - 1, -1, -1):
    if s[i] == 'L':
        deq.append(i)
    if s[i] == 'R':
        deq.appendleft(i)

ans = list(deq)
print(*ans)