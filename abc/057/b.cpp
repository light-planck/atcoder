#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n, m;
  cin >> n >> m;

  using P = pair<ll, ll>;
  
  vector<P> ab;
  rep(i, n) {
    ll a, b;
    cin >> a >> b;
    ab.emplace_back(a, b);
  }

  vector<P> cd;
  rep(i, m) {
    ll c, d;
    cin >> c >> d;
    cd.emplace_back(c, d);
  }

  rep(i, n) {
    auto [a, b] = ab[i];
    ll min_d = 1e18;
    ll ans = 0;

    rep(j, m) {
      auto [c, d] = cd[j];
      ll dist = abs(c-a) + abs(d-b);
      if (min_d > dist) {
        min_d = dist;
        ans = j + 1;
      }
    }

    cout << ans << '\n';
  }
  return 0;
}