#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;
using Graph = vector<vector<int>>;

Graph g;
vector<bool> seen;
vector<ll> t;

void dfs(int u) {
  seen[u] = true;
  for (auto next : g[u]) {
    if (seen[next]) continue;
    dfs(next);
  }
}

int main() {
  int n;
  cin >> n;
  seen.resize(n, false);
  t.resize(n);
  g.resize(n);
  rep(i, n) {
    cin >> t[i];
    int k;
    cin >> k;
    rep(j, k) {
      int a;
      cin >> a;
      a--;
      g[i].push_back(a);
    }
  }
  dfs(n - 1);
  ll ans = 0;
  rep(i, n) if(seen[i]) ans += t[i];
  cout << ans << endl;
  return 0;
}