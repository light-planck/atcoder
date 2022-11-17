#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  using P = pair<ll, ll>;

  ll n;
  cin >> n;

  vector<P> ab;
  rep(i, n) {
    ll a, b;
    cin >> a >> b;
    ab.emplace_back(a, b);
  }
  sort(ab.begin(), ab.end());

  vector<P> cd;
  rep(i, n) {
    ll c, d;
    cin >> c >> d;
    cd.emplace_back(c, d);
  }
  sort(cd.begin(), cd.end());

  vector<bool> used(n);
  ll ans = 0;
  rep(i, n) {
    auto [c, d] = cd[i];

    ll y = -1; ll id = -1;
    rep(j, n) {
      auto [a, b] = ab[j];

      if (a >= c or b >= d) continue;
      if (used[j]) continue;

      if (y < b) {
        y = b;
        id = j;
      }
    }

    if (id == -1) continue;

    ++ans;
    used[id] = true;
  }

  cout << ans << '\n';
  return 0;
}