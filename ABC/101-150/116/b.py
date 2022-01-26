s = int(input())
st = {s}

now = s
next = 0
i = 2
while True:
    if now % 2 == 0:
        next = now // 2   
    else:
        next = 3 * now + 1

    if next in st:
        break
    else:
        st.add(next)
        
    i += 1
    now = next

print(i)