#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  string s;
  cin >> s;

  bool ok1 = false;
  ll n = 8;
  for (ll i = 0; i < n; ++i) {
    for (ll j = i+1; j < n; ++j) {
      if (s[i] == 'B' and s[j] == 'B') {
        if (i%2 != j%2) ok1 = true;
      }
    }
  }

  bool ok2 = false;
  for (ll i = 0; i < n; ++i) {
    for (ll j = i+1; j < n; ++j) {
      for (ll k = j+1; k < n; ++k) {
        if (s[i] == 'R' and s[j] == 'K' and s[k] == 'R') ok2 = true;
      }
    }
  }

  if (ok1 and ok2) cout << "Yes" << '\n';
  else cout << "No" << '\n';
  return 0;
}