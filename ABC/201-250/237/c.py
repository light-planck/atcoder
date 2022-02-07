# (1)
# kasakaの先頭にaをつけるとakasakaとなり、回文である。
# したがって、sの末尾のaを取り除いた文字列t = kasakが回文ならば
# sは回文である。
# しかし、s = abaaの場合、t = abとなりtは回文ではないが、sにaをつけると
# s = aabaaとなり回文になる。よってこれは正しくない。

# (2)
# sの先頭、末尾の連続するaを取り除いた文字列tが回文ならば
# sは回文となりうる。
# s = abaaの場合、t = bとなり、tは回文であり、sもaをつければsも回文となる。
# しかし、s = abcbの場合t = bcbとなりtは回文となるが、sは回文になならない。
# よってこの考えは正しくない。

# (3)
# s[0] = left, s[n - 1] = rightとしてカーソルを置く。
# left = rightの場合、それぞれのカーソルをすすめる。
# sが回文であるならば最終的に、right <= leftとなっているはずである。
# sの先頭にaがついているとみなし、left = a以外、right = aのとき、
# rightのカーソルをすすめることができる。

s = input()
n = len(s)

left = 0
right = n - 1

while left < n and right >= 0:
    # 同じ文字ならカーソルをすすめる
    if s[left] == s[right]:
        left += 1
        right -= 1
    
    # s[l]がaでなく、s[r]がaのときsの先頭にaが付いている
    # ものと考えれば回文とみなせるのでrを進める
    elif s[left] != 'a' and s[right] == 'a':
        right -= 1
    
    # s[r] != s[l]の場合は回文でない
    else:
        break

if right <= left:
    print("Yes")
else:
    print("No")