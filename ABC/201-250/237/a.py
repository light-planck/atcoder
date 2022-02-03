n = int(input())

if -pow(2, 31) <= n and n < pow(2, 31):
    print("Yes")
else:
    print("No")