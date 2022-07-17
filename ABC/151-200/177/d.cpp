#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;

struct UnionFind {
  vector<int> parent;

  UnionFind(int n) : parent(n, -1) {}

  int find(int x) {
    if (parent[x] < 0) return x;

    parent[x] = find(parent[x]);
    return parent[x];
  }

  void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;

    if (parent[x] > parent[y]) swap(x, y);
    parent[x] += parent[y];
    parent[y] = x;
  }

  bool same(int x, int y) {
    return find(x) == find(y);
  }

  int size(int x) {
    return -parent[find(x)];
  }
};

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  ll n, m;
  cin >> n >> m;

  UnionFind uf(n);
  rep(i, m) {
    ll a, b;
    cin >> a >> b;
    a--; b--;
    uf.unite(a, b);
  }
  
  int ans = 0;
  rep(i, n) ans = max(ans, uf.size(i));
  cout << ans << "\n";
  return 0;
}