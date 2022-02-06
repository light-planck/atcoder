t = int(input())

for _ in range(t):
    a, s = map(int, input().split())
    
    # x = 0
    # y = s
    # ok = False
    # while y > 0:
    #     if x & y == a:
    #         ok = True
    #         print(x, y)
    #     x += 1
    #     y -= 1
    
    # if ok:
    #     print("Yes")
    # else:
    #     print("No")
    
    if a < s:
        a_set = set()
        idx = 0
        while a > 0:
            if a & 1:
                a_set.add(idx)
            a >>= 1
            idx += 1
        
        s_set = set()
        idx = 0
        while s > 0:
            if s & 1:
                s_set.add(idx)
            s >>= 1
            idx += 1

        ok = True
        for ai in a_set:
            if ai in s_set:
                ok = False
        
        if ok:
            print("Yes")
        else:
            print("No")
    else:
        print("No")