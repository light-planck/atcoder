#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  for (ll n = 4; n <= 100; ++n) {
    ll edge = n*(n-1)/2;

    if ((1LL<<edge) >= 100) {
      cout << n << '\n';
      break;
    }
  }
  return 0;
}