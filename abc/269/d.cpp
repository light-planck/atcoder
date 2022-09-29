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
#include <atcoder/dsu>
using namespace atcoder;


int main() {
  ll n;
  cin >> n;

  vector<ll> x(n), y(n);
  rep(i, n) cin >> x[i] >> y[i];

  using P = pair<ll, ll>;
  map<P, ll> mp;
  rep(i, n) {
    mp[{x[i], y[i]}] = i;
  }

  dsu uf(n);
  rep(i, n) {
    for (ll dx = -1; dx <= 1; ++dx) {
      if (dx == 0) {
        P p1 = make_pair(x[i]+dx, y[i]+1);
        P p2 = make_pair(x[i]+dx, y[i]-1);

        if (mp.count(p1)) uf.merge(i, mp[p1]);
        if (mp.count(p2)) uf.merge(i, mp[p2]);
      }
      else {
        P p1 = make_pair(x[i]+dx, y[i]);
        P p2 = make_pair(x[i]+dx, y[i]+dx);

        if (mp.count(p1)) uf.merge(i, mp[p1]);
        if (mp.count(p2)) uf.merge(i, mp[p2]);
      }
    }
  }

  ll ans = 0;
  rep(i, n) {
    if (uf.leader(i) == i) ++ans;
  }

  cout << ans << '\n';
  return 0;
}