#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll h, w;
  cin >> h >> w;

  vector<string> s(h);
  rep(i, h) cin >> s[i];

  ll x = 0; ll y = 0;
  rep(i, h) rep(j, w) {
    if (s[i][j] == 'S') {
      x = i;
      y = j;
    }
  }

  vector<pair<ll, ll>> dij = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
  vector seen(h, vector<ll>(w));

  auto dfs = [&](auto dfs, ll i, ll j, ll len) -> void {
    if (s[i][j] == '#') return;
    if (i == x and j == y) {
      if (len >= 4) {
        cout << "Yes" << '\n';
        exit(0);
      }
    }
    if (seen[i][j]) return;

    seen[i][j] = true;
    for (auto [di, dj] : dij) {
      ll ni = i + di; ll nj = j + dj;

      if (ni < 0 or ni >= h) continue;
      if (nj < 0 or nj >= w) continue;

      dfs(dfs, ni, nj, len+1);
    }
    seen[i][j] = false;
  };
  dfs(dfs, x, y, 0);

  cout << "No" << '\n';
  return 0;
}