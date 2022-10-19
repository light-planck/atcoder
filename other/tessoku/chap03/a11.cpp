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
  ll n, x;
  cin >> n >> x;

  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  ll ok = n;
  ll ng = -1;
  while (abs(ok-ng) > 1) {
    ll mid = (ok+ng) / 2;

    // a[mid]がx以上か
    if (a[mid] >= x) ok = mid;
    else ng = mid;
  }

  cout << ok+1 << '\n';
  return 0;
}