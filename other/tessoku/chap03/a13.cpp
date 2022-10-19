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

  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  ll ans = 0;
  ll r = 1;
  rep(l, n) {
    while (r < n and a[r]-a[l] <= k) {
      ++r;
    }
    --r;
    ans += r - l;
  }

  cout << ans << '\n';
  return 0;
}