#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll a, b;
  cin >> a >> b;

  string s;
  cin >> s;

  bool ok = true;
  for (ll i = 0; i < a+b+1; ++i) {
    if (i == a) {
      if (s[i] != '-') ok = false;
    }
    else {
      if (s[i] == '-') ok = false;
    }
  }

  if (ok) cout << "Yes" << '\n';
  else cout << "No" << '\n';
  return 0;
}