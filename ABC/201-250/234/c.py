from audioop import reverse


k = int(input())

ans = ""
while k > 0:
    if k & 1:
        ans += "2"
    else:
        ans += "0"
    k >>= 1

ans = ans[::-1]
print(ans)