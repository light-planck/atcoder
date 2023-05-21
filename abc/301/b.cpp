#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n;
  cin >> n;

  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  rep(i, n-1) {
    ll db = 1;
    if (a[i+1]-a[i] < 0) db = -1;

    for (ll b = a[i]; b != a[i+1]; b += db) {
      cout << b << '\n';
    }
  }
  cout << a.back() << '\n';
  return 0;
}