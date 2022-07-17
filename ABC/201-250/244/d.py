import sys, math, bisect
from collections import defaultdict, deque
input = sys.stdin.readline
sys.setrecursionlimit(10 ** 7)


def main():
    s = input().split()
    t = input().split()
    t = str(t[0]) + str(t[1]) + str(t[2])

    st = []
    st.append(str(s[0]) + str(s[1]) + str(s[2]))
    st.append(str(s[1]) + str(s[2]) + str(s[0]))
    st.append(str(s[2]) + str(s[0]) + str(s[1]))
    
    if t in st:
        print('Yes')
    else:
        print('No')


if __name__ == '__main__':
    main()