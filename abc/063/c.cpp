#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n;
  cin >> n;

  vector<ll> a(n);
  rep(i, n) cin >> a[i];
  sort(a.begin(), a.end());

  vector<ll> b;
  rep(i, n) {
    if (a[i]%10 != 0) b.emplace_back(a[i]);
  }

  ll ans = accumulate(a.begin(), a.end(), 0);
  if (ans%10 == 0) {
    if (b.size() == 0) ans = 0;
    else ans -= b[0];
  }

  cout << ans << '\n';
  return 0;
}