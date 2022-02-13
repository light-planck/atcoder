# import sys
# sys.setrecursionlimit(10 ** 6) 

# prod = 1
# def dfs(x):
#     y = x // 2
#     z = (x+2-1) // 2

#     global prod
#     if x < y * z:
#         dfs(y)
#         dfs(z)
#     else:
#         prod *= x
#         # prod %= MOD
#         return


# MOD = 998244353
# x = int(input())

# dfs(x)
# # prod %= MOD
# print(prod)


MOD = 998244353
x = int(input())

# ex = x // 2
# r = x % 2

# ans = 1

# ans *= (2 ** (ex-1)) % MOD
# ans %= MOD

# ans *= (3 ** r) % MOD
# ans %= MOD

# print(ans)

# x = 100
tmp = x
exp_2 = 0
while tmp > 0:
    exp_2 += 1
    tmp //= 2
print(exp_2)

tmp = x
exp_3 = 0
while tmp > 0:
    exp_3 += 1
    tmp //= 3
print(exp_3)

ans = 1
ans *= 2 ** (exp_2+1)
ans %= MOD

ans *= 3 ** ((exp_3-1) * exp_2)
ans %= MOD
print(ans)


# x = 3
# exp = 1
# while x < 200:
#     print(x, exp)
#     exp += 1
#     x *= 3