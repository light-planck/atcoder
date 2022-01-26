n = int(input())
a = list(map(int, input().split()))

sum = 0
for i in range(n):
    sum += (i + 1) * 4

for ai in a:
    sum -= ai

print(sum)