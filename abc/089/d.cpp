#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  ll h, w, d;
  cin >> h >> w >> d;

  map<ll, pair<ll, ll>> pos;
  rep(i, h) rep(j, w) {
    ll a;
    cin >> a;
    --a;
    pos[a] = {i, j};
  }

  vector<ll> sum(h*w + d);
  for (ll first = 0; first < d; ++first) {
    for (ll a = first; a < h*w; a += d) {
      auto [i, j] = pos[a];
      auto [ni, nj] = pos[a+d];

      sum[a+d] = sum[a] + abs(i-ni) + abs(j-nj);
    }
  }

  ll q;
  cin >> q;

  while (q--) {
    ll l, r;
    cin >> l >> r;
    --l; --r;

    cout << sum[r] - sum[l] << '\n';
  }
  return 0;
}