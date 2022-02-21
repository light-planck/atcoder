import heapq


n, m = map(int, input().split())

# aの最大値を取り出す
a = list(map(int, input().split()))
for i in range(n):
    a[i] *= -1

num_cnt = []
for ai in a:
    num_cnt.append([ai, 1])

for _ in range(m):
    b, c = map(int, input().split())
    c *= -1
    
    num_cnt.append([c, b])

heapq.heapify(num_cnt)

sum_cnt = 0
sum = 0
while sum_cnt < n:
    num, cnt = heapq.heappop(num_cnt)
    
    # すべて追加
    if sum_cnt + cnt <= n:
        sum -= num * cnt
        sum_cnt += cnt
    else:
        sum -= num * (n-sum_cnt)
        break

print(sum)