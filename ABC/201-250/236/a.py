s = input()
a, b = map(int, input().split())
a -= 1
b -= 1

ans = s[:a] + s[b] + s[a + 1:b] + s[a] + s[b + 1:]
print(ans)