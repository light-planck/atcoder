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
  ll n, k;
  cin >> n >> k;

  ll ans = 0;
  for (ll i = 1; i <= n; ++i) {
    for (ll j = 1; j <= n; ++j) {
      ll x = k - i - j;
      if (1 <= x and x <= n) ++ans;
    }
  }

  cout << ans << '\n';
  return 0;
}