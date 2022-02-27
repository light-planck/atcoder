import sys, math, bisect
from collections import defaultdict, deque
# input = sys.stdin.readline
sys.setrecursionlimit(10 ** 7)


def main():
    n = int(input())
    s = input()
    s = list(s)

    ans = ''
    i = 0
    while i < n:
        if s[i] == 'B':
            if i + 1 >= n:
                ans += 'B'
                break

            # BA => BBB => AB
            if s[i + 1] == 'A':
                s[i] = 'A'
                s[i + 1] = 'B'
                ans += 'A'
            
            # BB => A
            elif s[i + 1] == 'B':
                ans += 'A'
                i += 1
            
            # BC => BC
            else:
                ans += 'B'
        else:
            ans += s[i]
        
        i += 1
        
    print(ans)

if __name__ == '__main__':
    main()