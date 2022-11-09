#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n, k;
  cin >> n >> k;

  ll ans = k;
  rep(i, n-1) ans *= k - 1;
  cout << ans << '\n';
  return 0;
}