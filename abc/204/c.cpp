#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;
const int inf = 1e9;
const int mod = 1e9+7;
using Graph = vector<vector<int>>;

vector<int> seen;

void dfs(const Graph& G, int v) {
  seen[v] = true;
  for (auto nv : G[v]) {
    if (seen[nv]) continue;
    dfs(G, nv);
  }
}

int main() {
  int n, m;
  cin >> n >> m;

  Graph G(n);
  rep(i, m) {
    int a, b;
    cin >> a >> b;
    G[a-1].push_back(b-1);
  }

  int cnt = 0;

  // スタートする都市はn個
  for (int i = 0; i < n; i++) {
    seen.assign(n, false);
    dfs(G, i);

    // 到達できる都市をカウント
    for (int j = 0; j < n; j++) {
      if (seen[j]) cnt++;
    }
  }

  cout << cnt << endl;
  return 0;
}