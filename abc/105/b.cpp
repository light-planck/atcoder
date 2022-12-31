#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n;
  cin >> n;

  for (ll i = 0; i <= n; ++i) {
    for (ll j = 0; j <= n; ++j) {
      if (4*i + 7*j == n) {
        cout << "Yes" << '\n';
        return 0;
      }
    }
  }
  cout << "No" << '\n';
  return 0;
}