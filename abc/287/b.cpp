#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n, m;
  cin >> n >> m;

  vector<string> s(n);
  rep(i, n) cin >> s[i];

  vector<string> t(m);
  rep(i, m) cin >> t[i];

  ll ans = 0;
  rep(i, n) {
    rep(j, m) {
      if (s[i].substr(3) == t[j]) {
        ++ans;
        break;
      }
    }
  }

  cout << ans << '\n';
  return 0;
}