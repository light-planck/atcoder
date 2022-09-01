#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <deque>
#include <iostream>
#include <map>
#include <numeric>
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
  ll n, m;
  cin >> n >> m;

  using P = pair<ll, ll>;
  vector<P> ab;
  rep(i, m) {
    ll a, b;
    cin >> a >> b;
    --a; --b;
    ab.emplace_back(a, b);
  }

  ll ans = 0;
  rep(i, m) {
    dsu uf(n);
    rep(j, m) {
      if (i == j) continue;

      auto [a, b] = ab[j];
      uf.merge(a, b);
    }

    auto [a, b] = ab[i];
    if (not uf.same(a, b)) ++ans;
  }

  cout << ans << '\n';
  return 0;
}