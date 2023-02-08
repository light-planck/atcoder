#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;
#include <atcoder/all>
using namespace atcoder;


int main() {
  ll n, m;
  cin >> n >> m;

  dsu uf(n);
  ll ans = 0;
  rep(i, m) {
    ll a, b;
    cin >> a >> b;
    --a; --b;

    if (uf.same(a, b)) ++ans;
    uf.merge(a, b);
  }

  cout << ans << '\n';
  return 0;
}