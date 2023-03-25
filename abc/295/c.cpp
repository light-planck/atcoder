#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n;
  cin >> n;

  map<ll, ll> cnt;
  rep(i, n) {
    ll a;
    cin >> a;
    ++cnt[a];
  }

  ll ans = 0;
  for (auto [x, y] : cnt) {
    if (y >= 2) ans += y/2;
  }

  cout << ans << '\n';
  return 0;
}