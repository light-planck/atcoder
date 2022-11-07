#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n, m;
  cin >> n >> m;

  ll ans = 0;
  if (m/2 >= n) {
    ans = min(n, m/2);
    m -= 2*min(n, m/2);
    ans += m/4;
  }
  else ans = m/2;

  cout << ans << '\n';
  return 0;
}