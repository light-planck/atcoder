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
  
  map<ll, ll> cnt;
  rep(i, n) {
    ll a;
    cin >> a;
    ++cnt[a];
  }

  ll ans = 0;
  for (auto [a, c] : cnt) {
    if (c >= a) ans += c - a;
    else ans += c;
  }

  cout << ans << '\n';
  return 0;
}