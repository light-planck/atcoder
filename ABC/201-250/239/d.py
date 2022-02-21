def is_prime(n):
    if n <= 1:
        return False
    
    for i in range(2, n + 1):
        if i * i > n:
            break

        if n % i == 0:
            return False
    
    return True


a, b, c, d = map(int, input().split())

# すべてのiに対しi+jが素数となるようなjが
# 存在するならばaokiがかつ
aoki_win = True
for i in range(a, b + 1):
    sum_prime = False
    for j in range(c, d + 1):
        sum = i + j
        if is_prime(sum):
            sum_prime = True
    
    if not sum_prime:
        aoki_win = False

if aoki_win:
    print('Aoki')
else:
    print('Takahashi')