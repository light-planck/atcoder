#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;
using ull = unsigned long long;


int main() { 
  ll n = 64;
  
  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  ll ans = 0;
  rep(i, n) {
    ans += a[i] * (1ll << i);
  }
  cout << ans << '\n';
  return 0;
}