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

  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  ll ok = 0;
  ll ng = 3e5+1;
  while (abs(ok-ng) > 1) {
    ll mid = min(ok, ng) + abs(ok-ng)/2;
  
    auto check = [&]() {
      set<ll> less_mid;

      rep(i, n) {
        if (a[i] <= mid) less_mid.emplace(a[i]);
      }

      ll rem = less_mid.size();
      ll need = mid - rem;
      ll extra = n - rem;
      return extra/2 >= need;
    };
  
    if (check()) ok = mid;
    else ng = mid;
  }

  cout << ok << '\n';
  return 0;
}