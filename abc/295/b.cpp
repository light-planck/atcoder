#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll r, c;
  cin >> r >> c;

  vector<string> b(r);
  rep(i, r) cin >> b[i];

  rep(i, r) rep(j, c) {
    if (b[i][j] == '.' or b[i][j] == '#') continue;

    ll x = b[i][j] - '0';
    for (ll di = -x; di <= x; ++di) {
      for (ll dj = -x; dj <= x; ++dj) {
        if (abs(di)+abs(dj) > x) continue;
        ll ni = i + di; ll nj = j + dj;
        if (ni < 0 or ni >= r) continue;
        if (nj < 0 or nj >= c) continue;
        if (b[ni][nj] == '#') b[ni][nj] = '.';
      }
    }
    b[i][j] = '.';
  }

  rep(i, r) cout << b[i] << '\n';
  return 0;
}