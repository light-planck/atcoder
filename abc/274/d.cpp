#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <deque>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n, x, y;
  cin >> n >> x >> y;

  ll a0;
  cin >> a0;
  x -= a0;

  vector<ll> dx, dy;
  rep(i, n-1) {
    ll a;
    cin >> a;
    if (i & 1) dx.emplace_back(a);
    else dy.emplace_back(a);
  }

  ll s = dx.size();
  ll t = dy.size();

  bool ok1 = false;
  auto x_dfs = [&](auto x_dfs, ll i, ll sum) -> void {
    if (i == s) {
      if (sum == x) {
        ok1 = true;
      }
      return;
    }

    x_dfs(x_dfs, i+1, sum+dx[i]);
    x_dfs(x_dfs, i+1, sum-dx[i]);
  };
  x_dfs(x_dfs, 0, 0);

  bool ok2 = false;
  auto y_dfs = [&](auto y_dfs, ll i, ll sum) -> void {
    if (i == t) {
      if (sum == y) {
        ok2 = true;
      }
      return;
    }

    y_dfs(y_dfs, i+1, sum+dy[i]);
    y_dfs(y_dfs, i+1, sum-dy[i]);
  };
  y_dfs(y_dfs, 0, 0);

  if (ok1 and ok2) cout << "Yes" << '\n';
  else cout << "No" << '\n';
  return 0;
}