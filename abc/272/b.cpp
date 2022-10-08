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
  ll n, m;
  cin >> n >> m;

  vector<set<ll>> seen(m);

  rep(i, m) {
    ll k;
    cin >> k;

    rep(j, k) {
      ll x;
      cin >> x;
      --x;
      seen[i].emplace(x);
    }
  }

  bool ok = true;
  for (ll i = 0; i < n; ++i) {
    for (ll j = i+1; j < n; ++j) {
      bool ok2 = false;
      rep(k, m) {
        if (seen[k].count(i) and seen[k].count(j)) ok2 = true;
      }
      if (not ok2) ok = false;
    }
  }

  if (ok) cout << "Yes" << '\n';
  else cout << "No" << '\n';
  return 0;
}