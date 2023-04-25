#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  string s;
  cin >> s;

  ll X, Y;
  cin >> X >> Y;

  ll n = s.size();
  ll dir = 4;
  vector dpx(2*n + 1, vector<bool>(dir));
  dpx[0+n][0] = true;
  vector dpy(2*n + 1, vector<bool>(dir));
  dpy[0+n][0] = true;

  rep(i, n) {
    vector prev_x(2*n + 1, vector<bool>(dir));
    swap(prev_x, dpx);
    vector prev_y(2*n + 1, vector<bool>(dir));
    swap(prev_y, dpy);

    // 前進
    if (s[i] == 'F') {
      rep(d, dir) {
        for (ll x = 0; x <= 2*n; ++x) {
          if (not prev_x[x][d]) continue;
          if (x+1 <= 2*n) dpx[x+1][d] = true;
        }

        for (ll y = 0; y <= 2*n; ++y) {
          if (not prev_y[y][d]) continue;
          if (y+1 <= 2*n) dpy[y+1][d] = true;
        }
      }
    }

    // 方向転換
    if (s[i] == 'T') {
      const vector<pair<ll, ll>> dxy = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};

      rep(d, dir) {
        for (ll x = 0; x <= 2*n; ++x) {
          if (not prev_x[x][d]) continue;

          for (ll j = -1; j <= 1; j += 2) {
            ll nd = (d+j+dir) % dir;
            ll dx = dxy[nd].first;
            if (x+dx <= 2*n) prev_x[x+dx][nd] = true;
          }
        }

        for (ll y = 0; y <= 2*n; ++y) {
          if (not prev_y[y][d]) continue;

          for (ll j = -1; j <= 1; j += 2) {
            ll nd = (d+j+dir) % dir;
            ll dy = dxy[nd].second;
            if (y+dy <= 2*n) prev_y[y+dy][nd] = true;
          }
        }
      }
    }
  }

  rep(d, dir) {
    if (dpx[X+n][d] and dpy[Y+n][d]) {
      cout << "Yes" << '\n';
      return 0;
    }
  }
  cout << "No" << '\n';
  return 0;
}