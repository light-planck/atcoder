import math


def calculate_divisors(n):
    divisors = []
    
    for i in range(1, n + 1):
        if i * i > n:
            break

        if n % i != 0:
            continue

        divisors.append(i)
        if n / i != i:
            divisors.append(n // i)
    
    divisors.sort()
    return divisors


def is_prime(n):
    for i in range(2, n + 1):
        if i * i > n:
            break

        if n % i == 0:
            return False
    
    return True


a, b = map(int, input().split())
gcd = math.gcd(a, b)
divisors = calculate_divisors(gcd)

cnt = 0
for div in divisors:
    if div == 1:
        cnt += 1
    elif is_prime(div):
        cnt += 1

print(cnt)