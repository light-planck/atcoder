#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  ll n, m, q;
  cin >> n >> m >> q;

  // cnt[i][j]: [i, j]に含まれる列車の個数
  vector cnt(n, vector<ll>(n));
  rep(_, m) {
    ll l, r;
    cin >> l >> r;
    --l; --r;
    ++cnt[l][r];
  }

  // sum[i][j] = cnt[i][0] + cnt[i][1] + ... + cnt[i][j-1]
  vector sum(n+1, vector<ll>(n+1));
  rep(i, n) rep(j, n) {
    sum[i][j+1] += sum[i][j] + cnt[i][j];
  }

  rep(_, q) {
    ll p, q;
    cin >> p >> q;
    --p; --q;

    ll ans = 0;
    for (ll i = p; i <= q; ++i) {
      ans += sum[i][q+1] - sum[i][p];
    }
    cout << ans << '\n';
  }
  return 0;
}