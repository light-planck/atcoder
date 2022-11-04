#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;
#include <atcoder/modint>
using namespace atcoder;


int main() {
  ll n, m;
  cin >> n >> m;

  using mint = modint1000000007;
  vector<mint> fac(max(n, m)+1);
  fac[0] = 1;
  for (ll i = 1; i <= max(n,m); ++i) {
    fac[i] = i*fac[i-1];
  }

  mint ans = fac[n] * fac[m];
  if (n == m) ans *= 2;
  if (abs(n-m) > 1) ans = 0;
  cout << ans.val() << '\n';
  return 0;
}