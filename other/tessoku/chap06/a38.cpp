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
  ll d, n;
  cin >> d >> n;

  vector<tuple<ll, ll, ll>> lrh;
  rep(i, n) {
    ll l, r, h;
    cin >> l >> r >> h;
    lrh.emplace_back(l, r, h);
  }

  vector<ll> working_time(d+1, 24);
  working_time[0] = 0;
  
  for (auto [l, r, h] : lrh) {
    for (ll i = l; i <= r; ++i) {
      auto chmin = [](auto& a, auto b) { if (a > b) a = b; };
      chmin(working_time[i], h);
    }
  }

  ll ans = accumulate(working_time.begin(), working_time.end(), 0);
  cout << ans << '\n';
  return 0;
}