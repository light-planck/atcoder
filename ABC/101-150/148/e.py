'''
nが偶数のとき
n!! = 2 * 4 * 6 * 8 * ... * n
n!! / 2 = 1 * 2 * 3 * 4 * ... * n/2 = (n/2)!

nが奇数のとき
n!! = n! / (n - 1)!!

n!がpで何回割れるかを求める関数をg(n!, p)とすると
g(n!, p) = n/p + g((n/p)!, p)

n!!の末尾の0の個数はn!!を素因数分解したときの
2と5の指数のうちの小さい方であるから
ans = min(g(n!!, 2), g(n!!, 5))

g(n!!, 2) = g((n/2)!, 2) + n/2
g(n!!, 5) = g((n/5)!, 5) + n/5
'''


def count1(x, p):
    if x == 0:
        return 0
    
    return x // p + count1(x // p, p)

def count2(x, p):
    if n % 2 == 1:
        return count1(x, p) - count2(x-1, p)

    res = count1(x // 2, p)
    if p == 2:
        res += x // 2
    return res


n = int(input())
ans = min(count2(n, 2), count2(n, 5))
print(ans)