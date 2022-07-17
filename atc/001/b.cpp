#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;

struct UnionFind {
  vector<int> parent;

  UnionFind(int n):
  parent(n, -1)
  {}

  int find(int x) {
    // 自身が親の場合
    if (parent[x] < 0) {
      return x;
    }

    parent[x] = find(parent[x]);
    return parent[x];
  }

  void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) {
      return;
    }

    // 要素数が多い方をxに
    if (parent[x] > parent[y]) {
      swap(x, y);
    }

    // xを親に設定
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

  ll n, q;
  cin >> n >> q;

  UnionFind uf(n);

  rep(i, q) {
    ll p, a, b;
    cin >> p >> a >> b;
    if (p == 0) uf.unite(a, b);
    else {
      if (uf.same(a, b)) cout << "Yes\n";
      else cout << "No\n";
    }
  }
  return 0;
}