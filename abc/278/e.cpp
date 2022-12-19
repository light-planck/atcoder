#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


ll s[301][301][301];

int main() {
  ll H, W, n, h, w;
  cin >> H >> W >> n >> h >> w;

  vector a(H, vector<ll>(W));
  rep(i, H) rep(j, W) cin >> a[i][j];

  rep(i, H) rep(j, W) {
    s[i+1][j+1][a[i][j]] = s[i+1][j][a[i][j]] + 1;
  }
  return 0;
}