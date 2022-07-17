#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int,int>;

struct E {
  int to, co;
  E(int to=0, int co=0): to(to), co(co) {}
};

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<E>> g(n);
  rep(i,m) {
    int a, b, c;
    cin >> a >> b >> c;
    --a; --b;
    g[a].emplace_back(b,c);
  }
  const int INF = 1001001001;
  rep(sv,n) {
    vector<int> dist(n,INF);
    priority_queue<P, vector<P>, greater<P>> q;
    auto push = [&](int v, int d) {
      q.emplace(d,v);
    };
    for (auto&& e : g[sv]) push(e.to, e.co);
    while (!q.empty()) {
      auto [d,v] = q.top(); q.pop();
      if (dist[v] <= d) continue;
      dist[v] = d;
      for (auto&& e : g[v]) {
        push(e.to, d+e.co);
      }
    }
    int ans = dist[sv];
    if (ans == INF) ans = -1;
    cout << ans << endl;
  }
  return 0;
}