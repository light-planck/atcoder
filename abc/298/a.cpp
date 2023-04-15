#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n;
  cin >> n;

  string s;
  cin >> s;

  ll ok = 0;
  ll ng = 0;
  for (char c : s) {
    if (c == 'o') ++ok;
    if (c == 'x') ++ng;
  }

  if (ok > 0 and ng == 0) cout << "Yes" << '\n';
  else cout << "No" << '\n';
  return 0;
}