s = input()

min_d = 1e9
n = len(s)
for i in range(n - 2):
    d = abs(int(s[i:i + 3]) - 753)
    min_d = min(min_d, d)

print(min_d)