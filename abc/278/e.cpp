#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll H, W, n, h, w;
  cin >> H >> W >> n >> h >> w;

  vector a(H, vector<ll>(W));
  rep(i, H) rep(j, W) cin >> a[i][j];

  ll i = 0; ll j = 0;
  ll dir = 1;
  map<ll, ll> now;
  while (true) {
    auto ok = [&]() {
      if (i < 0 or i+h >= H) return false;
      if (j < 0 or j+w >= W) return false;
      return true;
    };
    
    if (not ok()) break;
    
    j += dir;
    if (dir == 1 and j == w) {
      // del: a[i][j] ~ a[i][w]
      // add: a[i+1][j] ~ a[i+1][w]

      dir = -1;
      ++i;
    }
    if (dir == -1 and j == 0) {
      dir = 1;
      ++i;
    }
  }
  return 0;
}