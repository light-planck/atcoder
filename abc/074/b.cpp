#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n;
  cin >> n;

  ll k;
  cin >> k;

  vector<ll> x(n);
  rep(i, n) cin >> x[i];

  ll ans = 0;
  rep(i, n) {
    ans += min(2*abs(x[i]-k), 2*abs(x[i]));
  }
  cout << ans << '\n';
  return 0;
}