#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n, p, q, r, s;
  cin >> n >> p >> q >> r >> s;
  --p; --q; --r; --s;

  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  ll d = q - p;
  for (ll i = 0; i < d+1; ++i) swap(a[p+i], a[r+i]);
  for (auto x : a) cout << x << '\n';
  return 0;
}