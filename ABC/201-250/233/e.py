s = input()
n = len(s)

# 各桁の総和
sum_x = 0
for c in s:
    sum_x += int(c)

# 今見ている桁の総和
now = 0
ans = ''
for c in reversed(s):
    now += sum_x
    ans += str(now % 10)

    sum_x -= int(c)

    # 繰り上げ分
    now //= 10

# 残った繰り上げ分を計算
while now:
    ans += str(now % 10)
    now //= 10

ans = ans[::-1]
print(ans)