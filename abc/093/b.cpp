#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll a, b, k;
  cin >> a >> b >> k;

  if (b-a+1 >= 2*k) {
    for (ll i = a; i < a+k; ++i) cout << i << '\n';
    for (ll i = b-k+1; i <= b; ++i) cout << i << '\n';
  }
  else for (ll i = a; i <= b; ++i) cout << i << '\n';
  return 0;
}