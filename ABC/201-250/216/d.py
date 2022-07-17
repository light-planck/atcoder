import sys, math, bisect
from collections import defaultdict, deque
input = sys.stdin.readline
sys.setrecursionlimit(10 ** 7)


def main():
    n, m = map(int, input().split())
    
    # i番目の筒の中身：a[i] = deque(1, 3, 0, ...)
    a = []
    
    # 左端のボール番号がnumである筒の番号idx
    # num_idx[num] = [idx0, idx3, ...]
    num_idx = [[] for _ in range(n + 1)]
    
    # m個の筒の中身をみる
    for idx in range(m):
        _ = int(input())
        aque = deque(list(map(int, input().split())))
        a.append(aque)

        # 左端のボール番号と筒の番号を紐付ける
        num_idx[aque[0]].append(idx)

    # 取り出すボールの番号
    que = deque()

    # 左端のボール番号が同じである筒が2個あるか確認
    for num in range(n + 1):
        if len(num_idx[num]) == 2:
            que.append(num)
    
    # 取り出す
    while que:
        # 取り出す番号
        now = que.popleft()
        for idx in num_idx[now]:

            # 取り出す
            a[idx].popleft()
            
            # 残りがあれば追加
            if len(a[idx]):
                num_idx[a[idx][0]].append(idx)
                
                # 追加した番号の筒が2個になったら候補として追加
                if len(num_idx[a[idx][0]]) == 2:
                    que.append(a[idx][0])

    
    # 全て取り出されたか確認
    for ai in a:
        if len(ai):
            print('No')
            exit()
    
    print('Yes')


if __name__ == '__main__':
    main()