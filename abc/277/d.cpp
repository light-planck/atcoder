#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;
#include <atcoder/dsu>
using namespace atcoder;


int main() {
  ll n, m;
  cin >> n >> m;

  vector<ll> a(n);
  rep(i, n) cin >> a[i];
  sort(a.begin(), a.end());

  dsu uf(n);
  rep(i, n) {
    ll j = (i+1) % n;
    if ((a[j]-a[i]+m) % m <= 1) uf.merge(i, j);
  }

  vector<ll> s(n);
  rep(i, n) {
    s[uf.leader(i)] += a[i];
  }

  ll ans = accumulate(a.begin(), a.end(), 0LL) - *max_element(s.begin(), s.end());
  cout << ans << '\n';
  return 0;
}