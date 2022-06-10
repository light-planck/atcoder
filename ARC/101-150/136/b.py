import sys, math, bisect
from collections import defaultdict, deque
# input = sys.stdin.readline
sys.setrecursionlimit(10 ** 7)


def main():
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    
    a_idx = [[] for _ in range(5000 + 1)]
    for i in range(n):
        a_idx[a[i]].append(set(i))

    print(a_idx)


if __name__ == '__main__':
    main()