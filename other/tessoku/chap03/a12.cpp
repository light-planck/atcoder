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

  ll ok = 1e9;
  ll ng = 0;
  while (abs(ok-ng) > 1) {
    ll mid = min(ok, ng) + abs(ok-ng)/2;
  
    auto check = [&]() {
      ll cnt = 0;
      rep(i, n) cnt += mid / a[i];
      return cnt >= k;
    };
  
    if (check()) ok = mid;
    else ng = mid;
  }

  cout << ok << '\n';
  return 0;
}