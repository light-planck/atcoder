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
    ll l = d % n;

    if (l == 0) {
      cout << k << '\n';
      continue;
    }

    if (n%l == 0) {
      if (k <= n/l) cout << (l*(k-1)) % n << '\n';
      else cout << (1+l*k-n-l) % n << '\n';
    }
    else {
      cout << (l*(k-1)) % n << '\n';
    }
  }
  return 0;
}