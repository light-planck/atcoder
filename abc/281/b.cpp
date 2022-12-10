#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  string s;
  cin >> s;

  if (s.size() != 8) {
    cout << "No" << '\n';
    return 0;
  }

  bool ok = true;
  if (isdigit(s[0]) or isdigit(s.back())) ok = false;
  if (islower(s[0]) or islower(s.back())) ok = false;
  ll x = stoll(s.substr(1, 6));
  if (x < 100000 or x >= 1000000) ok = false;

  if (ok) cout << "Yes" << '\n';
  else cout << "No" << '\n';
  return 0;
}