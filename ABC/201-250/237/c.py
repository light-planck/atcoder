s = input()
n = len(s)

l = 0
for i in range(n):
    if s[i] == 'a':
        l += 1
    else:
        break

r = n - 1
for i in range(n):
    if s[n - 1 - i] == 'a':
        r -= 1
    else:
        break

t = s[l:r + 1]
rev_t = t[::-1]
if t == rev_t:
    print("Yes")
else:
    print("No")