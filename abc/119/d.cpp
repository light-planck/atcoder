#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  ll a, b, q;
  cin >> a >> b >> q;

  const ll inf = 1e11;

  vector<ll> s(a);
  rep(i, a) cin >> s[i];
  s.emplace_back(-inf); s.emplace_back(inf);
  sort(s.begin(), s.end());

  vector<ll> t(b);
  rep(i, b) cin >> t[i];
  t.emplace_back(-inf); t.emplace_back(inf);
  sort(t.begin(), t.end());

  while (q--) {
    ll x;
    cin >> x;

    auto left = [&x](const vector<ll>& s) {
      return upper_bound(s.begin(), s.end(), x) - s.begin() - 1;
    };

    auto right = [&x](const vector<ll>& s) {
      return lower_bound(s.begin(), s.end(), x) - s.begin();
    };

    auto calc_dist = [&](vector<ll>& s, ll from, vector<ll>& t, ll to) {
      ll dist = abs(x - s[from]) + abs(s[from] - t[to]);
      return dist;
    };

    ll ans = 9e18;
    auto chmin = [](auto& a, auto b) { if (a > b) a = b; };

    // sl -> tl
    chmin(ans, calc_dist(s, left(s), t, left(t)));

    // sl -> tr
    chmin(ans, calc_dist(s, left(s), t, right(t)));

    // sr -> tl
    chmin(ans, calc_dist(s, right(s), t, left(t)));

    // sr -> tr
    chmin(ans, calc_dist(s, right(s), t, right(t)));

    // tl -> sl
    chmin(ans, calc_dist(t, left(t), s, left(s)));

    // tl -> sr
    chmin(ans, calc_dist(t, left(t), s, right(s)));

    // tr -> sl
    chmin(ans, calc_dist(t, right(t), s, left(s)));

    // tr -> sr
    chmin(ans, calc_dist(t, right(t), s, right(s)));

    cout << ans << '\n';
  }
  return 0;
}