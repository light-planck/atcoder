#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;

int main() {
  string S;
  cin >> S;

  ll n = ssize(S);
  ll ans = 0;
  rep(i, n) {
    for (ll j = 1; j <= n; ++j) {
      if (i + j > n) break;

      string t = S.substr(i, j);
      string rev_t = t;
      ranges::reverse(rev_t);

      if (t == rev_t) {
        ans = max<ll>(ans, ssize(t));
      }
    }
  }

  cout << ans << '\n';
}
