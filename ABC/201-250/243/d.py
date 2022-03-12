import sys, math, bisect
from collections import defaultdict, deque
input = sys.stdin.readline
sys.setrecursionlimit(10 ** 7)


def main():
    n, x = map(int, input().split())
    s = input()

    for i in range(n):
        if s[i] == 'U':
            x //= 2
        elif s[i] == 'L':
            x *= 2
        else:
            x = 2 * x + 1
    
    print(x)


if __name__ == '__main__':
    main()