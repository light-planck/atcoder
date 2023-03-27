#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll x, y, z, k;
  cin >> x >> y >> z >> k;

  vector a(x, 0ll);
  rep(i, x) cin >> a[i];

  vector b(y, 0ll);
  rep(i, y) cin >> b[i];

  vector c(z, 0ll);
  rep(i, z) cin >> c[i];

  vector<ll> ab;
  rep(i, x) {
    rep(j, y) {
      ab.emplace_back(a[i] + b[j]);
    }
  }
  sort(ab.rbegin(), ab.rend());
  while ((ll)ab.size() > k) ab.pop_back();

  vector<ll> ans;
  rep(i, ab.size()) {
    rep(j, z) {
      ans.emplace_back(ab[i] + c[j]);
    }
  }
  sort(ans.rbegin(), ans.rend());
  while ((ll)ans.size() > k) ans.pop_back();

  for (auto x : ans) cout << x << '\n';
  return 0;
}