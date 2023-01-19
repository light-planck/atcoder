#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n;
  cin >> n;

  for (ll i = n; i >= 0; --i) {
    ll x = llround(sqrt(i));
    if (x*x == i) {
      cout << i << '\n';
      return 0;
    }
  }
  return 0;
}