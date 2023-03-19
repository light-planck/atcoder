#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll L, n, m;
  cin >> L >> n >> m;

  vector<pair<ll, ll>> x;
  rep(i, n) {
    ll v, l;
    cin >> v >> l;
    x.emplace_back(v, l);
  }

  vector<pair<ll, ll>> y;
  rep(i, m) {
    ll v, l;
    cin >> v >> l;
    y.emplace_back(v, l);
  }

  ll i = 0; ll j = 0;
  ll ans = 0;
  while (i < n and j < m) {
    auto& [v1, l1] = x[i];
    auto& [v2, l2] = y[j];
    
    ll d = min(l1, l2);
    if (v1 == v2) {
      ans += d;
    }
    
    l1 -= d;
    l2 -= d;

    if (l1 == 0) ++i;
    if (l2 == 0) ++j;
  }

  cout << ans << '\n';
  return 0;
}