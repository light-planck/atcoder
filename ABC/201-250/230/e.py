"""
k = n // iとおけば
k <= n//i < k+1
n//(k+1) < i <= n//k
ゆえにkを満たすiの個数は
n//k - n//(k+1)個

式を実際に計算すると、
n = 10のとき
ans = 10 + 5 + 3 + 2 + 2 + 1 + 1 + 1 + 1 + 1
である。k= 2, 1といった小さい値のとき、明らかに
同じ計算を繰り返している。

k = n//iをみたすiの個数が2以上のときは、
n//k - n//(k+1) >= 2より、
およそ、k <= sqrt(n)の範囲である。
したがって、
(1) k <= sqrt(n)の範囲ではまとめてkを計算し、
(2)k > sqrt(n)のとき、つまり
n//i > sqrt(n)
n//(sqrt(n)+1) <= i < sqrt(n)のとき
kを一回ずつ足す。
どちらもO(sqrt(n))なので間に合う。
"""


n = int(input())

import math
M = int(math.sqrt(n))

ans = 0

# (1) k <= M
for k in range(1, M + 1):
    ans += (n//k - n//(k+1)) * k

# (2) k > M
for i in range(1, n//(M+1) + 1):
    ans += n // i

print(ans)