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

  ll min_a = a[0]; ll max_a = a.back();
  ll ans = 0;
  if (min_a < 0 and max_a > 0) ans = min_a * max_a;
  else if (min_a < 0 and max_a < 0) ans = a[n-2] * max_a;
  else if (min_a > 0 and max_a > 0) ans = min_a * a[1];
  
  cout << ans << '\n';
  return 0;
}