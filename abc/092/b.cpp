#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n;
  cin >> n;

  ll d, x;
  cin >> d >> x;

  ll ans = x;
  rep(i, n) {
    ll a;
    cin >> a;

    ll cnt = 0;
    for (ll j = 1; j <= d; j += a) {
      ++cnt;
    }

    ans += cnt;
  }

  cout << ans << '\n';
  return 0;
}