#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  string s;
  cin >> s;

  ll X, Y;
  cin >> X >> Y;

  const ll n = 4;
  constexpr ll inf = 1ll << 60;
  using P = pair<ll, ll>;
  const vector<P> dir = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};

  vector<set<P>> dp(n);
  rep(i, n) {
    if (i == 0) dp[0].emplace(0, 0);
    else dp[i].emplace(inf, inf);
  }

  for (char c : s) {
    vector<set<P>> prev(n);
    swap(prev, dp);

    // 1進める
    if (c == 'F') {
      rep(i, n) {
        for (auto [x, y] : prev[i]) {
          if (x == inf and y == inf) continue;

          auto [dx, dy] = dir[i];
          dp[i].emplace(x+dx, y+dy);
        }
      }
    }

    // 方向転換
    if (c == 'T') {
      rep(i, n) {
        for (auto [x, y] : prev[i]) {
          if (x == inf and y == inf) continue;

          for (ll di = -1; di <= 1; di += 2) {
            ll idx = (i+di+n) % n;
            dp[idx].emplace(x, y);
          }
        }
      }
    }
  }

  for (auto st : dp) {
    for (auto [x, y] : st) {
      if (x == X and y == Y) {
        cout << "Yes" << '\n';
        return 0;
      }
    }
  }

  cout << "No" << '\n';
  return 0;
}