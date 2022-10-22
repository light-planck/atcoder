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
  ll n, s;
  cin >> n >> s;

  vector<ll> x(n);
  rep(i, n) cin >> x[i];
  rep(i, n) x[i] -= s;

  ll ans = 0;
  rep(i, n) ans = gcd(ans, x[i]);

  cout << ans << '\n';
  return 0;
}