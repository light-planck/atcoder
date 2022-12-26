#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


const vector<pair<ll, ll>> dij = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};


int main() {
  ll h, w;
  cin >> h >> w;

  vector a(h, vector<ll>(w));
  rep(i, h) rep(j, w) cin >> a[i][j];

  auto check = [&]() {
    bool diff = true;
    ll bin = a[0][0];
    if (bin == a[0][1]) diff = false;
    if (bin == a[1][0]) diff = false;
    if (bin == a[1][1]) diff = false;
    if (diff) {
      cout << -1 << '\n';
      exit(0);
    }

    diff = true;
    bin = a[0][w-1];
    if (bin == a[0][w-2]) diff = false;
    if (bin == a[1][w-1]) diff = false;
    if (bin == a[1][w-2]) diff = false;
    if (diff) {
      cout << -1 << '\n';
      exit(0);
    }

    diff = true;
    bin = a[h-1][0];
    if (bin == a[h-1][1]) diff = false;
    if (bin == a[h-2][0]) diff = false;
    if (bin == a[h-2][1]) diff = false;
    if (diff) {
      cout << -1 << '\n';
      exit(0);
    }

    diff = true;
    bin = a[h-1][w-1];
    if (bin == a[h-1][w-2]) diff = false;
    if (bin == a[h-2][w-1]) diff = false;
    if (bin == a[h-2][w-2]) diff = false;
    if (diff) {
      cout << -1 << '\n';
      exit(0);
    }
  };
  check();

  ll ans = 0;
  rep(i, h) rep(j, w) {
    bool alone = true;

    for (auto [di, dj] : dij) {
      ll ni = i + di; ll nj = j + dj;
      if (ni < 0 or ni >= h) continue;
      if (nj < 0 or nj >= w) continue;

      if (a[i][j] == a[ni][nj]) alone = false;
    }

    if (alone) ++ans;
  }

  if (ans%2 == 0) cout << ans/2 << '\n';
  else cout << -1 << '\n';
  return 0;
}