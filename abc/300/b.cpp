#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll h, w;
  cin >> h >> w;

  vector<string> a(h);
  rep(i, h) cin >> a[i];

  vector<string> b(h);
  rep(i, h) cin >> b[i];

  // 縦シフト
  auto col_shift = [&h, &w](const vector<string> s) {
    auto res = s;
    rep(i, h) {
      rep(j, w) {
        res[(i-1+h)%h][j] = s[i][j];
      }
    }
    return res;
  };

  // 横シフト
  auto row_shift = [&h, &w](const vector<string> s) {
    auto res = s;
    rep(i, h) {
      rep(j, w) {
        res[i][(j-1+w)%w] = s[i][j];
      }
    }
    return res;
  };

  auto now = a;
  rep(s, h) {
    if (s > 0) now = col_shift(now);
    auto tmp = now;

    rep(t, w) {
      if (t > 0) now = row_shift(now);

      if (now == b) {
        cout << "Yes" << '\n';
        return 0;
      }
    }

    now = tmp;
  }

  cout << "No" << '\n';
  return 0;
}