#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n, m;
  cin >> n >> m;

  vector<set<ll>> st(m);
  rep(i, m) {
    ll c;
    cin >> c;
    rep(_, c) {
      ll a;
      cin >> a;
      st[i].emplace(a);
    }
  }

  ll ans = 0;
  for (ll bit = 0; bit < (1<<m); ++bit) {
    set<ll> s;
    rep(i, m) {
      if ((bit>>i) & 1) {
        for (auto x : st[i]) {
          s.emplace(x);
        }
      }
    }
    
    if ((ll)s.size() == n) ++ans;
  }

  cout << ans << '\n';
  return 0;
}