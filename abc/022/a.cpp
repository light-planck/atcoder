#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n, s, t;
  cin >> n >> s >> t;

  ll w;
  cin >> w;

  ll ans = 0;
  if (s <= w and w <= t) ++ans;
  rep(i, n-1) {
    ll a;
    cin >> a;
    w += a;
    if (s <= w and w <= t) ++ans;
  }

  cout << ans << '\n';
  return 0;
}