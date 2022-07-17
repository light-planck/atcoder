#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;
const int inf = 1e9;
const int mod = 1e9+7;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> h(n);
  rep(i, n) cin >> h[i];
  vector<vector<int>> g(n);
  int cnt = 0;

  rep(i, m) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  rep(i, n) {
    bool good = true;

    if (g[i].size() == 0) {
      cnt++;
      continue;
    }

    for (auto x : g[i]) {
      if (h[i] <= h[x]) good = false;
    }
    if (good) cnt++;
  }

  cout << cnt << endl;
  return 0;
}