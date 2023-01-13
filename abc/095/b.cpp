#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n, x;
  cin >> n >> x;

  vector<ll> m(n);
  rep(i, n) cin >> m[i];

  sort(m.begin(), m.end());
  ll mn = m[0];
  ll ans = (x - accumulate(m.begin(), m.end(), 0ll)) / mn + n;
  cout << ans << '\n';
  return 0;
}