import sys, math, bisect
from collections import defaultdict, deque
input = sys.stdin.readline
sys.setrecursionlimit(10 ** 7)
"""
すべての料理を作るのにかかる時間をsum_tとする。
オーブン1とオーブン2の2つのオーブンがあり、いくつかの料理を
オーブン1で作るものと、2で作るものに分ける。
オーブン1で作るのにかかった時間をt1とすると
オーブン2での調理時間はsum_t - t1。よってそのグループ分けで料理するときに
かかる時間はオーブンでの調理時間の最大値であるmax(t1, sum_t - t1)である。
"""

def main():
    n = int(input())
    t = list(map(int, input().split()))

    sum_t = sum(t)

    # 片方のオーブンで料理することを考える
    # dp[i + 1][j] 料理iまでを作るのにかかる時間jとなるような選び方が存在するか
    dp = [[0] * (sum_t+1) for _ in range(n + 1)]
    dp[0][0] = 1

    for i in range(n):
        for j in range(sum_t + 1):

            # 料理iを選ばない
            if dp[i][j]:
                dp[i + 1][j] = 1
            
            # 料理iを選ぶ
            if j - t[i] >= 0 and dp[i][j - t[i]]:
                dp[i + 1][j] = 1
    
    ans = 10 ** 18
    for j in range(sum_t + 1):
        if dp[n][j]:
            time = max(j, sum_t - j)
            ans = min(ans, time)
    print(ans)


if __name__ == '__main__':
    main()