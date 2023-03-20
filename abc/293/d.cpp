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
  ll ring = 0;
  rep(i, m) {
    ll a, c;
    char b, d;
    cin >> a >> b >> c >> d;
    --a; --c;
    if (uf.same(a, c)) ++ring;
    else uf.merge(a, c);
  }

  ll ans = 0;
  rep(i, n) if (uf.leader(i)==i) ++ans;
  cout << ring << " " << ans-ring << '\n';
  return 0;
}