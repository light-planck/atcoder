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

  vector<ll> a(n+2);
  for (ll i = 1; i <= n; ++i) cin >> a[i];

  ll sum = 0;
  rep(i, n+1) sum += abs(a[i+1] - a[i]);

  for (ll i = 1; i <= n; ++i) {
    ll ans = sum;
    ans -= abs(a[i] - a[i-1]) + abs(a[i+1] - a[i]);
    ans += abs(a[i+1] - a[i-1]);
    cout << ans << '\n';
  }
  return 0;
}