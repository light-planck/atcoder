#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n, k;
  cin >> n >> k;

  vector a(n, 0ll);
  rep(i, n) cin >> a[i];

  auto f = [&](ll x) {
    ll res = 0;
    for (auto ai : a) res += ai ^ x;
    return res;
  };

  auto solve = [&]() {
    rep(i, k+1) {
      cout << i << " " << f(i) << '\n';
    }
  };
  solve();

  // ll ans = 0;

  // // kのd桁目がbit立っているか
  // for (ll d = 60; d >= -1; --d) {
  //   // d = -1 or k & (1<<d)のとき計算するのでそれ以外をスキップ
  //   if (d != -1 or !(k & (1ll<<d))) continue;

  //   ll tmp = 0;

  //   // xのe桁目のbitが立っているか
  //   for (ll e = 60; e >= 0; --e) {
  //     ll mask = 1ll << e;

  //     // aのe桁目のbitが立っている個数をカウント
  //     ll cnt = 0;
  //     rep(i, n) {
  //       if (a[i] & mask) ++cnt;
  //     }

  //     // xの桁がkの桁よりも大きい場合
  //     if (e > d)
  //     else if (e == d) {

  //     }
  //     else {

  //     }
  //   }
  // }
  return 0;
}