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
  ll n, m, b;
  cin >> n >> m >> b;

  vector<ll> a(n);
  rep(i, n) cin >> a[i];
  ll sum_a = accumulate(a.begin(), a.end(), 0);

  vector<ll> c(m);
  rep(i, m) cin >> c[i];
  ll sum_c = accumulate(c.begin(), c.end(), 0);

  ll ans = m*(sum_a+n*b) + n*sum_c;
  cout << ans << '\n';
  return 0;
}