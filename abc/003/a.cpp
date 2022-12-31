#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n;
  cin >> n;

  ll ans = 0;
  rep(i, n) ans += (i+1) * 10000;
  ans /= n;

  cout << ans << '\n';
  return 0;
}