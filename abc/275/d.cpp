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
  ll n;
  cin >> n;

  map<ll, ll> memo;

  auto dfs = [&](auto dfs, ll x) -> ll {
    if (x == 0) return memo[x] = 1;

    ll res = 0;
    if (memo.count(x/2)) res += memo[x/2];
    else res += dfs(dfs, x/2);

    if (memo.count(x/3)) res += memo[x/3];
    else res += dfs(dfs, x/3);

    return memo[x] = res;
  };

  ll ans = dfs(dfs, n);
  cout << ans << '\n';
  return 0;
}