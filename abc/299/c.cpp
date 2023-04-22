#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n;
  cin >> n;

  string s;
  cin >> s;

  ll ans = 0;
  rep(j, 2) {
    ll len = 0;
    rep(i, n) {
      if (s[i] == '-') {
        ans = max(ans, len);
        len = 0;
      }
      else ++len;
    }
    reverse(s.begin(), s.end());
  }

  if (ans == 0) ans = -1;
  cout << ans << '\n';
  return 0;
}