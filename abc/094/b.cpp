#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n, m, x;
  cin >> n >> m >> x;
  --x;

  set<ll> st;
  rep(i, m) {
    ll a;
    cin >> a;
    --a;
    st.emplace(a);
  }

  ll ans = 1ll << 60;
  ll cost = 0;
  for (ll i = x; i < n; ++i) {
    if (st.count(i)) ++cost;
  }
  auto chmin = [](auto& a, auto b) { if (a > b) a = b; };
  chmin(ans, cost);

  cost = 0;
  for (ll i = x; i >= 0; --i) {
    if (st.count(i)) ++cost;
  }
  chmin(ans, cost);

  cout << ans << '\n';
  return 0;
}