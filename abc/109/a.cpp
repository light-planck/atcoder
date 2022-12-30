#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll a, b;
  cin >> a >> b;

  for (ll c = 1; c <= 3; ++c) {
    if ((a*b*c) % 2 == 1) {
      cout << "Yes" << '\n';
      return 0;
    }
  }

  cout << "No" << '\n';
  return 0;
}