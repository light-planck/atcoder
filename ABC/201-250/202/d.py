import sys, math, bisect
from collections import defaultdict, deque
input = sys.stdin.readline
sys.setrecursionlimit(10 ** 7)


from functools import lru_cache
@lru_cache
def comb(n, r):
    res = 1
    
    for i in range(r):
        res *= n - i
        res //= i + 1
    
    return res


def main():
    a, b, k = map(int, input().split())
    
    ans = ''
    while a + b:

        # 先頭がaとなるような場合の数
        cnt_a = 0
        if a >= 1:
            cnt_a = comb(a - 1 + b, a - 1)
        
        # 先頭がaとなる場合
        if k <= cnt_a:
            ans += 'a'
            a -= 1
        else:
            ans += 'b'
            b -= 1
            k -= cnt_a
    
    print(ans)


if __name__ == '__main__':
    main()