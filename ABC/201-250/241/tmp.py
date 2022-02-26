import sys, math, bisect
from collections import defaultdict, deque
# input = sys.stdin.readline
sys.setrecursionlimit(10 ** 7)


def main():
    n = int(input())
    s = [input() for _ in range(n)]
    
    # よこ
    for i in range(n):
        for i in range(n):
            # 白マスの個数
            white_cnt = 0
        
            # 黒マスの個数
            black_cnt = 0
            
            if s[i][j] == '.':
                white_cnt += 1
            else:
                black_cnt += 1
            
            if white_cnt == 3:
                break
            if black_cnt == 4:
                print('Yes')
                exit()

    
    # 斜め　傾きマイナス
    for i in range(n):

        # 白マスの個数
        white_cnt = 0
        
        # 黒マスの個数
        black_cnt = 0
        for j in range(n):
            if s[i][j] == '.':
                white_cnt += 1
            else:
                black_cnt += 1
            
            # s[i][j]から出発して
            # .が3個または黒マスが6個または座標外
            # になるまで(i, j)に(1, 1)を足していく
            
            di, dj = 1, 1
            while i + di < n and j + dj < n:
                if s[i + di][j + dj] == '.':
                    white_cnt += 1
                else:
                    black_cnt += 1
                
                if white_cnt == 3:
                    break
                if black_cnt == 6:
                    print('Yes')
                    exit()

                di += 1
                dj += 1
        
        # 斜め　傾きプラス
    for i in range(n):

        # 白マスの個数
        white_cnt = 0
        
        # 黒マスの個数
        black_cnt = 0
        for j in range(n):
            if s[i][j] == '.':
                white_cnt += 1
            else:
                black_cnt += 1
            
            # s[i][j]から出発して
            # .が3個または黒マスが6個または座標外
            # になるまで(i, j)に(1, 1)を足していく
            
            di, dj = 1, -1
            while i + di < n and j + dj < n:
                if s[i + di][j + dj] == '.':
                    white_cnt += 1
                else:
                    black_cnt += 1
                
                if white_cnt == 3:
                    break
                if black_cnt == 6:
                    print('Yes')
                    exit()

                di += 1
                dj -= 1


if __name__ == '__main__':
    main()