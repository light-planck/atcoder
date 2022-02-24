# sを時計回りに90度回転
def rotate(s):
    n = len(s)
    res = [['.'] * n for _ in range(n)]

    # 反時計回り
    # (i, j) => (n-1-j, i)

    # 時計回り
    # (i, j) => (j, n - 1 - i)
    for i in range(n):
        for j in range(n):
            if s[i][j] == '#':
                res[j][n - 1 - i] = '#'
                
    return res

# 平行移動
def translate(s):
    n = len(s)
    res = [['.'] * n for _ in range(n)]
    
    # 平行移動させるために#の座標i, jの最小値を求める
    i_min, j_min = 300, 300
    
    for i in range(n):
        for j in range(n):
            if s[i][j] == '#':
                i_min = min(i_min, i)
                j_min = min(j_min, j)
    
    for i in range(n):
        for j in range(n):
            if s[i][j] == '#':
                res[i][j] = '.'
                res[i - i_min][j - j_min] = '#'

    return res

def is_same(s, t):
    return translate(s) == translate(t)


n = int(input())

s = [input() for _ in range(n)]
t = [input() for _ in range(n)]

# sを3回90度回転させる
for _ in range(4):
    if is_same(s, t):
        print('Yes')
        exit()
    
    s = rotate(s)

print('No')