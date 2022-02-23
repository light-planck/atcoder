class UnionFind:
    def __init__(self, n):
        self.parent = [-1] * n

    def find(self, x):
        if self.parent[x] < 0:
            return x
        else:
            self.parent[x] = self.find(self.parent[x])
            return self.parent[x]
    
    def unite(self, x, y):
        x = self.find(x)
        y = self.find(y)
        
        if x == y:
            return
    
        # 要素数が大きい方に小さいほうを加える
        # yの方が要素数が大きい場合
        if self.parent[x] > self.parent[y]:
            x, y = y, x
        
        # xを親にする
        self.parent[x] += self.parent[y]
        self.parent[y] = x

    def is_same(self, x, y):
        return self.find(x) == self.find(y)

    def size(self, x):
        return -self.parent[self.find(x)]


n, m = map(int, input().split())

g = [[] for _ in range(n)]
for _ in range(m):
    a, b = map(int, input().split())
    a -= 1; b -= 1
    
    # a < b
    g[a].append(b)

uf = UnionFind(n)
ans = [0]

# 連結成分の個数
now = 0

# 逆から考える
for i in reversed(range(n)):
    if i == 0:
        break
    
    now += 1

    for v in g[i]:
        if uf.is_same(i, v):
            continue

        uf.unite(i, v)
        now -= 1
    
    ans.append(now)

ans = ans[::-1]
for x in ans:
    print(x)