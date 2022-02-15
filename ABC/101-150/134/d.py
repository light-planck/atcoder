n = int(input())
a = [None] + list(map(int, input().split()))

b = [0] * (n+1)

for i in range(n, 0, -1):
    sum = 0
    
    for j in range(i * 2, n + 1, i):
        sum ^= b[j]
    
    b[i] = sum ^ a[i]

ans = []
for i in range(1, n + 1):
    if b[i] == 1:
        ans.append(i)

print(len(ans))
if len(ans) > 0:
    print(*ans)