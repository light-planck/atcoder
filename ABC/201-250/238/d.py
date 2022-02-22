"""
x and y = a
x + y = s

aを2進数に変換したときの1となっている
桁はx, yも1となる。x, yのそれ以外の桁は不明だが、それらを0
とすると、x = y = aとなるので、x + y >= 2 * a。
よって、条件はs >= 2 * a。
x', y'を2進数表記のaが1となっている桁がともに0であり、
x', y'が共に1となるような桁が存在しない数とすれば、
x = x' + a, y = y' + a書け、
x' + y' and a == 0となる。
ここで、s = x + y = (x' + a) + (y' + a) = 2 * a + x' + y'より、
x' + y' = s - 2 * aなので
s >= 2 * a and s - 2 * a and a == 0
がyesとなる条件である。
"""


def judge(a, s):
    return s >= 2 * a and (s - 2 * a & a == 0)


t = int(input())

for _ in range(t):
    a, s = map(int, input().split())
    if judge(a, s):
        print('Yes')
    else:
        print('No')