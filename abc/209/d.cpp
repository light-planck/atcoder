#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;
const int inf = 1e9;
const int mod = 1e9+7;
using Graph = vector<vector<int>>;

int main() {
  int n, q;
  cin >> n >> q;

  Graph g(n);
  rep(i, n-1) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  vector<int> dist(n, -1);
  dist[0] = 0;
  queue<int> que;
  que.push(0);

  while (!que.empty()) {
    int v = que.front();
    que.pop();
    for (auto nv : g[v]) {
      if (dist[nv] != -1) continue;
      dist[nv] = dist[v] + 1;
      que.push(nv);
    }
  }

  rep(i, q) {
    int c, d;
    cin >> c >> d;
    c--; d--;
    if ((dist[c] % 2) == (dist[d] % 2)) cout << "Town" << endl;
    else cout << "Road" << endl;
  }
  return 0;
}