#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;

int main() { 
  ll n, d;
  cin >> n >> d;

  vector<string> s(n);
  rep(i, n) cin >> s[i];

  ll ans = 0;
  ll now = 0;
  rep(j, d) {
    bool ok = true;
    rep(i, n) {
      if (s[i][j] == 'x') ok = false;
    }

    if (ok) ++now;
    else now = 0;

    ans = max(ans, now);
  }

  cout << ans << '\n';
  return 0;
}