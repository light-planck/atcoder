#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  string s;
  cin >> s;

  ll ans = 0;
  bool zero = false;
  for (auto c : s) {
    if (c == '+') {
      if (not zero) ++ans;
      zero = false;
    }
    else if (c == '0') zero = true;
  }
  if (not zero) ++ans;

  cout << ans << '\n';
  return 0;
}