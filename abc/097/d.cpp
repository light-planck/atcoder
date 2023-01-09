#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;
#include <atcoder/dsu>
using namespace atcoder;


int main() {
  ll n, m;
  cin >> n >> m;

  vector<ll> p(n);
  rep(i, n) cin >> p[i], --p[i];

  vector<ll> x(m), y(m);
  rep(i, m) cin >> x[i] >> y[i], --x[i], --y[i];

  dsu uf(n);
  rep(i, m) {
    uf.merge(x[i], y[i]);
  }

  ll ans = 0;
  rep(i, n) {
    if (uf.same(p[i], i)) ++ans;
  }
  cout << ans << '\n';
  return 0;
}