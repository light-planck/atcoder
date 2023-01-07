#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;
#include <atcoder/dsu>
using namespace atcoder;


int main() {
  ll n, m;
  cin >> n >> m;

  dsu uf(n);
  rep(i, m) {
    ll u, v;
    cin >> u >> v;
    --u; --v;
    uf.merge(u, v);
  }

  ll ans = 0;
  rep(i, n) {
    if (uf.leader(i) == i) ++ans;
  }

  cout << ans << '\n';
  return 0;
}