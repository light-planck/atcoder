import sys, math, bisect
from collections import defaultdict, deque
input = sys.stdin.readline
sys.setrecursionlimit(10 ** 7)


def main():
    n, m = map(int, input().split())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    
    dic = defaultdict(int)
    for ai in a:
        dic[ai] += 1
    
    for bi in b:
        if dic[bi] >= 1:
            dic[bi] -= 1
        else:
            print('No')
            exit()
    
    print('Yes')


if __name__ == '__main__':
    main()