N = 2 ** 20
q = int(input())

dict = dict()
for _ in range(q):
    t, x = map(int, input().split())
    
    if t == 1:
        h = x % N

        while h in dict:
            h += 1
        
        # hが見つかったら
        dict[h] = x

    if t == 2:
        x %= N
        
        # xで置換されていたら
        if x in dict:
            print(dict[x])
        else:
            print(-1)