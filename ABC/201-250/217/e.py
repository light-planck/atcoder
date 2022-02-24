q = int(input())

from collections import deque
que = deque()

import heapq
hq = []
heapq.heapify(hq)

import sys
for _ in range(q):
    input = sys.stdin.readline
    
    tx = list(map(int, input().split()))
    t = tx[0]
    
    # queの末尾に追加
    if t == 1:
        x = tx[1]
        que.append(x)
    
    # heapqに要素があるなら最小値、ないならqueなら左端を出力
    elif t == 2:
        if len(hq):
            print(heapq.heappop(hq))
        else:
            print(que.popleft())
    
    # queの要素をheapqに追加
    elif t == 3:
        while que:
            x = que.pop()
            heapq.heappush(hq, x)