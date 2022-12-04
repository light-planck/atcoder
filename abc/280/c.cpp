#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  string s;
  cin >> s;

  string t;
  cin >> t;

  ll n = s.size();
  ll ans = t.size();
  rep(i, n) {
    if (s[i] != t[i]) {
      ans = i+1;
      break;
    }
  }

  cout << ans << '\n';
  return 0;
}