n, q = map(int, input().split())

a = list(map(int, input().split()))
dic = dict()
for i in range(n):
    if a[i] not in dic:
        dic[a[i]] = []
    dic[a[i]].append(i + 1)

for _ in range(q):
    x, k = map(int, input().split())
    if x not in dic or len(dic[x]) < k:
        print(-1)
    else:
        print(dic[x][k - 1])