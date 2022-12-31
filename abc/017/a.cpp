#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll ans = 0;
  rep(i, 3) {
    ll s, e;
    cin >> s >> e;
    ans += s * e / 10;
  }

  cout << ans << '\n';
  return 0;
}