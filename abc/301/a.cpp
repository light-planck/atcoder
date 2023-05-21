#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n;
  cin >> n;

  string s;
  cin >> s;

  ll t = 0;
  for (auto c : s) {
    if (c == 'T') ++t;
  }

  if (t > n-t) cout << 'T' << '\n';
  else if (t < n-t) cout << 'A' << '\n';
  else {
    if (s.back() == 'T') cout << 'A' << '\n';
    else cout << 'T' << '\n';
  }
  return 0;
}