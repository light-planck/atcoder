import sys, math, bisect
from collections import defaultdict, deque
sys.setrecursionlimit(10 ** 7)


def n2ten(s, n):
    res = 0
    s = s[::-1]
    base = 1

    for c in s:
        d = int(c)
        res += d * base
        base *= n
    
    return res


def main():
    s = input()

    m = int(input())

    if len(s) == 1:
        if int(s) <= m:
            print(1)
        else:
            print(0)
        exit()

    d = 0
    for c in s:
        d = max(d, int(c))
    
    ok = d
    ng = m + 1
    while abs(ok-ng) > 1:
        mid = (ok+ng) // 2

        if (n2ten(s, mid) <= m):
            ok = mid
        else:
            ng = mid
    
    print(ok - d)


if __name__ == '__main__':
    main()