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

  ll n;
  cin >> n;

  vector<double> s(2);
  rep(i, 2) cin >> s[i];

  vector<double> t(2);
  rep(i, 2) cin >> t[i];

  vector<double> x(n), y(n), r(n);
  rep(i, n) cin >> x[i] >> y[i] >> r[i];

  vector edge(n, vector<ll>());
  for (ll i = 0; i < n; ++i) for (ll j = i+1; j < n; ++j) {
    double d = hypot(x[i]-x[j], y[i]-y[j]);
    if (d*d > (r[i]+r[j])*(r[i]+r[j]) or d*d < (r[i]-r[j])*(r[i]-r[j])) continue;
      edge[i].emplace_back(j);
      edge[j].emplace_back(i);
  }

  ll start = 0;
  ll goal = 0;
  rep(i, n) {
    if ((s[0] - x[i])*(s[0] - x[i]) + (s[1] - y[i])*(s[1] - y[i]) == r[i]*r[i]) start = i;
    if ((t[0] - x[i])*(t[0] - x[i]) + (t[1] - y[i])*(t[1] - y[i]) == r[i]*r[i]) goal = i;
  }

  vector<ll> seen(n);
  auto dfs = [&](auto dfs, ll v) -> void {
    seen[v] = true;

    for (auto to : edge[v]) {
      if (seen[to]) continue;

      dfs(dfs, to);
    }
  };
  dfs(dfs, start);

  if (seen[goal]) cout << "Yes" << "\n";
  else cout << "No" << "\n";

  // cout << start << endl;
  // cout << goal << "\n";

  // rep(i, n) {
  //   cout << i << ": " << seen[i] << "\n";
  // }

  // rep(i, n) {
  //   cout << i << ": ";
  //   for (auto v : edge[i]) cout << v << " ";
  //   cout << "\n";
  // }
  return 0;
}