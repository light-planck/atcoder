#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdint>
#include <deque>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
#define rng(a) (a).begin(),(a).end()
#define rrng(a) (a).rbegin(),(a).rend()
using namespace std;
using ll = long long;
using P = pair<long long, long long>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;


int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  ll n, k;
  cin >> n >> k;

  vector<ll> a(k);
  rep(i, k) {
    cin >> a[i];
    --a[i];
  }

  vector<double> x(n), y(n);
  rep(i, n) cin >> x[i] >> y[i];

  constexpr double inf = 1e18;
  vector<vector<double>> dist(n, vector<double>(n, inf));

  rep(i, n) {
    for (auto j : a) {
      double d = (x[i]-x[j])*(x[i]-x[j]) + (y[i] - y[j])*(y[i] - y[j]);

      chmin(dist[i][j], d);
    }
  }

  double ans = 0;
  rep(i, n) {
    double tmp = inf;

    for (auto j : a) {
      chmin(tmp, dist[i][j]);
    }

    chmax(ans, tmp);
  }

  ans = sqrt(ans);
  printf("%.10f\n", ans);
  return 0;
}