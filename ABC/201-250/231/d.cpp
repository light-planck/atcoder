#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;
using Graph = vector<vector<int>>;

struct UnionFind{
  vector<int> p;
  vector<int> rank;

  UnionFind(int n) {
    p.resize(n);
    rank.resize(n);
    for (int i = 0; i < n; i++) {
      p[i] = i;
      rank[i] = 0;
    }
  }

  int find(int x) {
    if (x != p[x]) p[x] = find(p[x]);
    return p[x];
  }

  void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;

    // 木の高さが低い方を高い方に合併する
    if (rank[x] > rank[y]) p[y] = x;
    else {
      p[x] = y;

      // 木の高さが同じなら代表の高さを+1
      if (rank[x] == rank[y]) rank[y]++;
    }
  }

  bool same(int x, int y) {
    if (find(x) == find(y)) return true;
    else return false;
  }
};

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int n, m;
  cin >> n >> m;
  Graph g(n);
  UnionFind uf(n);

  rep(i, m) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    g[a].push_back(b);
    g[b].push_back(a);
    if (uf.same(a, b)) {
      cout << "No\n";
      return 0;
    }
    uf.unite(a, b);
  }

  // 隣り合う人が3人以上の場合No
  rep(i, n) if (g[i].size() >= 3) {
    cout << "No\n";
    return 0;
  }

  cout << "Yes\n";
  return 0;
}