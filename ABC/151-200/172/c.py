n, m, k = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))

# aの累積和
sum_a = [0]
for i in range(n):
    sum_a.append(sum_a[i] + a[i])

# bの累積和
sum_b = [0]
for i in range(m):
    sum_b.append(sum_b[i] + b[i])

# aの本をa_cnt冊、bの本をb_cnt冊読むとする
# 求める答えはa_cnt + b_cntの最大値である
# まず、a_cnt = 0として固定する
# b_cnt = mとし、これを1ずつ減らしていく。
# s[a_cnt] + s[b_cnt] <= kとなったらmax_b = b_cnt
# として記憶しa_cnt += 1として動かす
# 同様のことをやるが、b_cnt = max_bから
# 探索していく

b_cnt = m
ans = 0
for a_cnt in range(n + 1):
    while b_cnt >= 0 and sum_a[a_cnt] + sum_b[b_cnt] > k:
        b_cnt -= 1
    
    if sum_a[a_cnt] + sum_b[b_cnt] <= k:
        ans = max(ans, a_cnt + b_cnt)

print(ans)