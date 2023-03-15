#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  ll t;
  cin >> t;

  while (t--) {
    ll n = 3;
    vector<ll> x(n);
    rep(i, n) cin >> x[i];
    ll a = accumulate(x.begin(), x.end(), 0ll) / 3;
    bool ok = true;

    if ((x[0]+x[1]+x[2]) %3 != 0) ok = false;
    if (x[0]%2!=x[1]%2 or x[1]%2!=x[2]%2 or x[2]%2!=x[0]%2) ok = false;
    if (a%2 != x[0]%2) ok = false;

    if (not ok) {
      cout << -1 << '\n';
      continue;
    }

    ll d = 0;
    rep(i, n) d += abs(x[i] - a);
    cout << d/4 << '\n';
  }
  return 0;
}