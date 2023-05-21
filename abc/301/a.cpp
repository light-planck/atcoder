#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n;
  cin >> n;

  string s;
  cin >> s;

  ll cnt = 0;
  for (auto c : s) {
    if (c == 'T') ++cnt;
  }

  if (cnt > n-cnt) cout << 'T' << '\n';
  else if (cnt < n-cnt) cout << 'A' << '\n';
  else {
    ll t = 0;
    ll a = 0;
    for (auto c : s) {
      if (c == 'T') ++t;
      if (c == 'A') ++a;

      if (t == cnt) {
        cout << 'T' << '\n';
        exit(0);
      }
      if (a == cnt) {
        cout << 'A' << '\n';
        exit(0);
      }
    }
  }
  return 0;
}