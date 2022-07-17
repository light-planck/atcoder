from collections import deque

n = int(input())
a = list(map(int, input().split()))

deq = deque()
now = None
cnt = 0
for ai in a:
    deq.append(ai)

    if now == ai:
        cnt += 1
    else:
        now = ai
        cnt = 1
    
    # 消える
    if now == cnt:
        for _ in range(cnt):
            _ = deq.pop()

        # 消えたら末尾を参照
        # 空なら無視
        
        if deq:
            now = deq.pop()
            cnt = 1
            
            # 末尾の数字が連続していたらカウントする
            while deq:
                x = deq.pop()
                if x == now:
                    cnt += 1
                else:
                    deq.append(x)
                    break
            
            for _ in range(cnt):
                deq.append(now)
    
    print(len(deq))