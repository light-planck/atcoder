#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n;
  cin >> n;

  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  ll ans = 0;
  ll r = 1;
  rep(l, n) {
    if (l == r) ++r;
    
    while (r < n and (a[r]>a[r-1])) {
      ++r;
    }

    ans += r - l;
    if (r == l) ++r;
  }

  cout << ans << '\n';
  return 0;
}