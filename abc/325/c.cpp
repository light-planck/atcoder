#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;

#include <atcoder/dsu>
using namespace atcoder;

int main() {
  ll H, W;
  cin >> H >> W;

  vector<string> S(H);
  rep(i, H) cin >> S[i];

  const vector<pair<ll, ll>> dij = {{1, 0}, {0, 1},   {-1, 0}, {0, -1},
                                    {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};

  dsu uf(H * W);

  rep(i, H) {
    rep(j, W) {
      if (S[i][j] == '.') continue;

      for (auto [di, dj] : dij) {
        ll ni = i + di;
        ll nj = j + dj;

        if (ni < 0 || ni >= H || nj < 0 || nj >= W) continue;
        if (S[ni][nj] == '#') {
          uf.merge(i * W + j, ni * W + nj);
        }
      }
    }
  }

  ll ans = 0;
  rep(i, H) {
    rep(j, W) {
      if (S[i][j] == '.') continue;
      if (uf.leader(i * W + j) == i * W + j) ++ans;
    }
  }

  cout << ans << '\n';
}
