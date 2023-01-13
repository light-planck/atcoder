#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll x;
  cin >> x;

  vector<ll> ans = {1};
  for (ll i = 2; i < x; ++i) {
    ll a = i * i;
    while (a <= x) {
      ans.emplace_back(a);
      a *= i;
    }
  }

  sort(ans.begin(), ans.end());
  cout << ans.back() << '\n';
  return 0;
}