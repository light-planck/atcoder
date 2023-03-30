#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n;
  cin >> n;

  vector a(n, 0ll);
  rep(i, n) cin >> a[i];

  ll sum = accumulate(a.begin(), a.end(), 0ll);
  if (sum%n != 0) {
    cout << -1 << '\n';
    return 0;
  }

  ll ans = 0;
  rep(i, n-1) {
    ll left = 0;
    for (ll l = 0; l <= i; ++l) left += a[l];
    ll right = 0;
    for (ll r = i+1; r < n; ++r) right += a[r];
    if (left != (i+1)*sum/n or right != (n-i-1)*sum/n) ++ans;
  }

  cout << ans << '\n';
  return 0;
}