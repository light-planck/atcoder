# n = 7, 777, 7777, ...は
# n_i+1 = 10 * n_i + 7と書ける。
# n_i = 0 (mod k)となるようなものを求めたい。
# ゆえに、m_i = n_i % kとおけば
# m_i+1 = (10 * m_i + 7) % k
# m_iの取りうる範囲は0 <= m_i <= k - 1であり、
# nは単調増加であるから、mの値はループする。
# m = 0ならばその時点でidxを出力し、
# ループを一周してもm = 0とならなければ-1を出力する。

k = int(input())

idx = 1
seen = set()
m = 7 % k
while True:
    if m == 0:
        print(idx)
        break

    if m in seen:
        print(-1)
        break
    else:
        seen.add(m)
        m = (10 * m + 7) % k
    
    idx += 1