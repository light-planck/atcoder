#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n = 3;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  ll k;
  cin >> k;

  while (k--) {
    sort(a.begin(), a.end());
    a.back() *= 2;
  }

  cout << accumulate(a.begin(), a.end(), 0ll) << '\n';
  return 0;
}