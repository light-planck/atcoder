#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  ll t;
  cin >> t;

  while (t--) {
    ll n, d, k;
    cin >> n >> d >> k;
    --k;
    ll g = gcd(n, d);
    cout << (k/(n/g) + k*d) % n << '\n';
  }
  return 0;
}