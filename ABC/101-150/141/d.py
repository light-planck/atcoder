'''
heapqで価格を記憶し、m回分最大値を取り出してそれを2で割り
heapqに追加する操作をする
'''


import heapq


n, m = map(int, input().split())
a = list(map(int, input().split()))

for i in range(n):
    a[i] *= -1

heapq.heapify(a)

for _ in range(m):
    max_a = -heapq.heappop(a)
    max_a //= 2
    max_a *= -1
    heapq.heappush(a, max_a)

print(-sum(a))