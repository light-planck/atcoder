import sys, math, bisect
from collections import defaultdict, deque
input = sys.stdin.readline
sys.setrecursionlimit(10 ** 7)


def main():
    N, K = map(int, input().split())
    A = list(map(int, input().split()))

    next_dbl = [(i + x) % N for i, x in enumerate(A)]
    sum_dbl = A[:]
    
    print(next_dbl)
    print(sum_dbl)


if __name__ == '__main__':
    main()