#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;
const int inf = 1e9;
const int mod = 1e9+7;
using Graph = vector<vector<int>>;

vector<bool> seen;
vector<int> ans;

void dfs(const Graph& G, int v) {
  seen[v] = true;
  ans.push_back(v);
  for (auto nv : G[v]) {
    if (seen[nv]) continue;
    dfs(G, nv);
    ans.push_back(v);
  }
}

int main() {
  int n;
  cin >> n;

  Graph G(n);
  rep(i, n-1) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  for (int i = 0; i < n; i++) {
    sort(all(G[i]));
  }

  seen.assign(n, false);
  dfs(G, 0);
  for (auto v : ans) cout << v + 1 << endl;
  return 0;
}