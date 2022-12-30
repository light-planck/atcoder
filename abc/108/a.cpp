#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll k;
  cin >> k;

  ll ans = (k/2) * (k-k/2);
  cout << ans << '\n';
  return 0;
}