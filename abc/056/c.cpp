#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll x;
  cin >> x;

  for (ll t = 1; t < 1e5; ++t) {
    if (t*(t+1) >= 2*x) {
      cout << t << '\n';
      break;
    }
  }
  return 0;
}