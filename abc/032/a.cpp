#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll a, b, n;
  cin >> a >> b >> n;

  for (ll i = n; ; ++i) {
    if (i%a == 0 and i%b == 0) {
      cout << i << '\n';
      return 0;
    }
  }
  return 0;
}