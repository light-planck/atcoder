#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;


int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  ll x, y, a, b, c;
  cin >> x >> y >> a >> b >> c;

  vector<ll> p(a);
  rep(i, a) cin >> p[i];
  sort(p.rbegin(), p.rend());

  vector<ll> q(b);
  rep(i, b) cin >> q[i];
  sort(q.rbegin(), q.rend());

  vector<ll> r(c);
  rep(i, c) cin >> r[i];
  sort(r.rbegin(), r.rend());

  vector<ll> apples;
  rep(i, x) apples.push_back(p[i]);
  rep(i, y) apples.push_back(q[i]);
  rep(i, c) apples.push_back(r[i]);
  sort(apples.rbegin(), apples.rend());

  ll ans = 0;
  rep(i, x + y) ans += apples[i];
  cout << ans << "\n";
  return 0;
}