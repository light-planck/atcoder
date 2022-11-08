#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll k, s;
  cin >> k >> s;

  ll ans = 0;
  rep(x, k+1) {
    rep(y, k+1) {
      ll z = s - x - y;
      if (0 <= z and z <= k) ++ans;
    }
  }

  cout << ans << '\n';
  return 0;
}