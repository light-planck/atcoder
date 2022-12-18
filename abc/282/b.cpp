#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n, m;
  cin >> n >> m;

  vector<string> s(n);
  rep(i, n) cin >> s[i];

  ll ans = 0;
  
  for (ll i = 0; i < n; ++i) {
    for (ll j = i+1; j < n; ++j) {
      bool ok = true;

      rep(k, m) {
        if (s[i][k] == 'x' and s[j][k] == 'x') ok = false;
      }

      if (ok) ++ans;
    }
  }

  cout << ans << '\n';
  return 0;
}