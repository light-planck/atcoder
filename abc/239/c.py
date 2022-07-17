x1, y1, x2, y2 = map(int, input().split())

dx1 = [1, 1, -1, -1]
dy1 = [2, -2, 2, -2]

dx2 = [2, 2, -2, -2]
dy2 = [1, -1, 1, -1]

points1 = []
for dx in dx1:
    for dy in dy1:
        x = x1 + dx
        y = y1 + dy
        points1.append([x, y])

for dx in dx2:
    for dy in dy2:
        x = x1 + dx
        y = y1 + dy
        points1.append([x, y])


for dx in dx1:
    for dy in dy1:
        x = x2 + dx
        y = y2 + dy

        if [x, y] in points1:
            print('Yes')
            exit()

for dx in dx2:
    for dy in dy2:
        x = x2 + dx
        y = y2 + dy

        if [x, y] in points1:
            print('Yes')
            exit()

print('No')