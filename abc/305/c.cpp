#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;

int main() {
  ll H, W;
  cin >> H >> W;

  vector<string> S(H);
  for (auto& s : S) cin >> s;

  const vector<pair<ll, ll>> dij = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

  rep(i, H) {
    rep(j, W) {
      if (S[i][j] == '#') continue;

      ll cnt = 0;
      for (auto [di, dj] : dij) {
        ll ni = i + di;
        ll nj = j + dj;
        if (ni < 0 or ni >= H or nj < 0 or nj >= W) continue;

        if (S[ni][nj] == '#') ++cnt;
      }

      if (cnt >= 2) {
        cout << i + 1 << " " << j + 1 << '\n';
        exit(0);
      }
    }
  }
  return 0;
}
