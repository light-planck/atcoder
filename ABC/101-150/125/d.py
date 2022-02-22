n = int(input())
a = list(map(int, input().split()))

"""
任意のi, jに対し、ai, ajの符号を反転できる。
ゆえに、aの負数が偶数個のとき、全て符号を反転できるので、
答えはs = |a0| + |a1| + ... + |an-1|。
それ以外の場合、min(|ai|) * 2をsから引いたものが答え
"""

sum_a = 0
min_a = 10 ** 9
neg_cnt = 0
for ai in a:
    if ai < 0:
        neg_cnt += 1
    ai = abs(ai)
    sum_a += ai
    min_a = min(min_a, ai)

if neg_cnt % 2 == 1:
    sum_a -= 2 * min_a

print(sum_a)