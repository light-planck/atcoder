#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n;
  cin >> n;

  ll ans = 1;
  rep(i, n) {
    ll t;
    cin >> t;
    ans = lcm(ans, t);
  }

  cout << ans << '\n';
  return 0;
}