n, m = map(int, input().split())
s = input().split()
t = input().split()

dic = dict()
for ti in t:
    if ti not in dic:
        dic[ti] = 1

for si in s:
    if si in dic:
        print("Yes")
    else:
        print("No")