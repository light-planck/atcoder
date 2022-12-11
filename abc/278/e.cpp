#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll H, W, n, h, w;
  cin >> H >> W >> n >> h >> w;

  vector a(H, vector<ll>(W));
  rep(i, H) rep(j, W) cin >> a[i][j];

  vector s(H, vector<map<ll, ll>>(W));
  rep(i, H) rep(j, W) {
    s[i+1][j+1][a[i][j]] = ++s[i+1][j][a[i][j]];
  }
  return 0;
}