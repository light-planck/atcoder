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

  vector<ll> p(n);
  rep(i, n) cin >> p[i];

  map<ll, ll> pos;
  rep(i, n) {
    pos[p[i]] = i;
  }

  vector<ll> cnt(n);
  rep(i, n) {
    for (ll j = -1; j <= 1; ++j) {
      ll c = ((p[i]+j)%n - pos[p[i]] + n) % n;
      ++cnt[c];
    }
  }

  ll ans = 0;
  auto chmax = [](auto& a, auto b) { if (a < b) a = b; };
  rep(i, n) chmax(ans, cnt[i]);
  cout << ans << '\n';
  return 0;
}