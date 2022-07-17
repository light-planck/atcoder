#include <algorithm>
#include <bitset>
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
#include <string>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(x) (x).begin(),(x).end()
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

  vector<ll> x(n), y(n);
  rep(i, n) cin >> x[i] >> y[i];

  if (k == 1) {
    cout << "Infinity" << "\n";
    return 0;
  }

  // seen[i][j]: 点i, jを見たか
  vector<vector<ll>> seen(n, vector<ll>(n));

  ll ans = 0;

  for (ll i = 0; i < n; ++i) {
    for (ll j = i + 1; j < n; ++j) {
      if (seen[i][j]) continue;

      // 直線上の点
      vector<ll> points = {i, j};

      // 同一線上にあるか判定
      for (ll k = j + 1; k < n; ++k) {
        ll s = (x[j] - x[i]) * (y[k] - y[i]) - (x[k] - x[i]) * (y[j] - y[i]);
        if (s == 0) {
          points.emplace_back(k);
        }
      }

      // 一度見た点の組み合わせは今後見ない
      for (ll l = 0; l < (ll)points.size(); l++) {
        for (ll m = l + 1; m < (ll)points.size(); ++m) {
          seen[points[l]][points[m]] = true;
          seen[points[m]][points[l]] = true;
        }
      }

      if ((ll)points.size() >= k) ++ans;
    }
  }

  cout << ans << "\n";
  return 0;
}