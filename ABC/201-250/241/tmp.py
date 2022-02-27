import sys, math, bisect
from collections import defaultdict, deque
from functools import lru_cache
input = sys.stdin.readline
sys.setrecursionlimit(10 ** 7)
MOD = 998244353


def main():
    n = int(input())
    s = [input().rstrip() for _ in range(n)]
    print(s)


if __name__ == '__main__':
    main()