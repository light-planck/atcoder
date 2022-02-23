"""
区間スケジューリング問題
[start, end]の予定が複数個あり、同時に予定を選べないとき
予定をできるだけ多く選ぶには予定をendで昇順にソートし、
順に予定を見ていく。
start < prev_endならスキップし、それ以外は予定を選択する。
終了時刻が早いものを選ぶと残りの時間で選べる予定の選択肢を残せる。

この問題の場合、壁[l, r]をrでソートし、
prev_r + d - 1 >= lならば壁を同時に破壊できるのでスキップする。prev_rはそのまま。
prev_r + d - 1 < lならば同時に破壊できないのでcnt+=1。prev_rを更新する。
"""


n, d = map(int, input().split())

rl = []
for _ in range(n):
    l, r = map(int, input().split())
    rl.append([r, l])
rl.sort()

cnt = 0
prev_r = -10**9 - 10
for r, l in rl:
    if prev_r + d - 1 < l:
        cnt += 1
        prev_r = r

print(cnt)