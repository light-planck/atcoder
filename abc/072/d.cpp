#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n;
  cin >> n;

  vector<ll> p(n);
  rep(i, n) cin >> p[i];

  ll ans = 0;
  rep(i, n) {
    if (p[i] == i+1) {
      ll j = i + 1;
      if (i == n-1) j = i - 1;

      swap(p[i], p[j]);
      ++ans;
    }
  }

  cout << ans << '\n';
  return 0;
}