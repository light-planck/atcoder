import sys, math, bisect
from collections import defaultdict, deque
input = sys.stdin.readline
sys.setrecursionlimit(10 ** 7)


def main():
    a = list(map(int, input().split()))
    
    nxt = a[0]
    cnt = 1
    while cnt < 3:
        nxt = a[nxt]
        cnt += 1
    
    print(nxt)


if __name__ == '__main__':
    main()