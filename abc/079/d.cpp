#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <deque>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll h, w;
  cin >> h >> w;

  ll n = 10;
  constexpr ll inf = 9e18;
  vector dist(n, vector<ll>(n, inf));
  rep(i, n) dist[i][i] = 0;
  rep(i, n) rep(j, n) cin >> dist[i][j];

  vector a(h, vector<ll>(w));
  rep(i, h) rep(j, w) cin >> a[i][j];

  auto chmin = [](auto& a, auto b) { if (a > b) a = b; };
  rep(k, n) rep(i, n) rep(j, n) {
    chmin(dist[i][j], dist[i][k]+dist[k][j]);
  }

  ll ans = 0;
  rep(i, h) rep(j, w) {
    if (a[i][j] == -1 or a[i][j] == 1) continue;

    ans += dist[a[i][j]][1];
  }

  cout << ans << '\n';
  return 0;
}