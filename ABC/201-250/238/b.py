n = int(input())
a = list(map(int, input().split()))

sum = 0
deg = [0, 360]
for ai in a:
    if sum + ai >= 360:
        sum = sum + ai - 360
    else:
        sum += ai
    deg.append(sum)
    
deg.sort()

ans = 0
for i in range(len(deg) - 1):
    ans = max(ans, deg[i + 1] - deg[i])
    
print(ans)