#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  string s;
  cin >> s;

  ll ans = 1;
  ll n = s.size();
  ll i = 1;
  while (i < n) {
    bool skip = false;

    ++ans;

    if (i+1 < n) {
      if (s[i] == '0' and s[i+1] == '0') {
        skip = true;
      }
    }

    if (skip) i += 2;
    else ++i;
  }

  cout << ans << '\n';
  return 0;
}