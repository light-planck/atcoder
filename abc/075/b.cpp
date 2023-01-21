#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll h, w;
  cin >> h >> w;

  vector<string> s(h);
  rep(i, h) cin >> s[i];

  const vector<pair<ll, ll>> dij = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};

  rep(i, h) {
    rep(j, w) {
      if (s[i][j] == '#') {
        cout << '#';
        continue;
      }

      ll cnt = 0;
      for (auto [di, dj] : dij) {
        ll ni = i+di; ll nj = j+dj;
        if (ni < 0 or ni >= h) continue;
        if (nj < 0 or nj >= w) continue;

        if (s[ni][nj] == '#') ++cnt;
      }
      cout << cnt;
    }
    cout << '\n';
  }
  return 0;
}