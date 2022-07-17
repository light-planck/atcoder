import sys, math, bisect
from collections import defaultdict, deque
# input = sys.stdin.readline
sys.setrecursionlimit(10 ** 7)


def main():
    n = int(input())
    s = [input() for _ in range(n)]
    
    # よこ
    for i in range(n):
        for j in range(n):
            if j + 5 >= n:
                break
            
            white = 0
            for k in range(6):
                if j + k >= n:
                    break


                if s[i][j + k] == '.':
                    white += 1
            
            if white <= 2:
                print('Yes')
                exit()
                
    # たて
    for j in range(n):
        for i in range(n):
            
            if i + 5 >= n:
                break

            white = 0
            for k in range(6):
                if i + k >= n:
                    break


                if s[i + k][j] == '.':
                    white += 1
            
            if white <= 2:
                print('Yes')
                exit()
    
    # ななめ負
    for i in range(n):
        for j in range(n):
            # 座標に収まってない場合スキップ
            if i + 5 >= n or j + 5 >= n:
                continue

            white = 0
            for k in range(6):
                if s[i + k][j + k] == '.':
                    white += 1

            if white <= 2:
                print('Yes')
                exit()
    
    # ななめ正
    for i in range(n):
        for j in range(n):
            # 座標に収まっているか
            if i + 5 >= n or j - 5 < 0:
                continue

            white = 0
            for k in range(6):
                if s[i + k][j - k] == '.':
                    white += 1

            if white <= 2:
                print('Yes')
                exit()
    
    print('No')


if __name__ == '__main__':
    main()