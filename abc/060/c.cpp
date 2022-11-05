#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n, t;
  cin >> n >> t;

  vector<ll> enter(n);
  rep(i, n) cin >> enter[i];

  ll ans = 0;
  rep(i, n-1) {
    ans += min(t, enter[i+1]-enter[i]);
  }
  ans += t;

  cout << ans << '\n';
  return 0;
}