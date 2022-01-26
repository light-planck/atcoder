#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;
const int inf = 1e9;
const int mod = 1e9+7;
using Graph = vector<vector<int>>;

int main() {
  int n, m;
  cin >> n >> m;

  Graph g(n);
  rep(i, m) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  vector<int> dist(n, -1);
  dist[0] = 0;
  queue<int> q;
  q.push(0);

  // dp計算用の頂点記録
  // queueに追加された順に記録
  vector<int> dv;

  while (!q.empty()) {
    int v = q.front();
    q.pop();

    dv.push_back(v);

    for (auto nv : g[v]) {
      if (dist[nv] != -1) continue;
      dist[nv] = dist[v] + 1;
      q.push(nv);
    }
  }

  // dp[i] 頂点iまでの最短経路
  vector<int> dp(n);
  dp[0] = 1;

  // 頂点vとそれに隣接するnvの距離が1のとき
  // dpを加算していく
  for (auto v : dv) {
    for (auto nv : g[v]) {
      if (dist[nv] == dist[v] + 1) {
        (dp[nv] += dp[v]) %= mod;
      }
    }
  }
  
  cout << dp[n-1] << endl;
  return 0;
}