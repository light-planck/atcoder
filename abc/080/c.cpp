#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }


int main() {
  ll n;
  cin >> n;

  ll zone = 10;
  vector f(n, vector<ll>(zone));
  rep(i, n) rep(j, zone) cin >> f[i][j];

  vector p(n, vector<ll>(zone + 1));
  rep(i, n) rep(j, 11) cin >> p[i][j];

  constexpr ll inf = 9e18;
  ll ans = -inf;

  for (ll bit = 1; bit < (1<<zone); ++bit) {
    vector<ll> c(n);
    // 店iと出店する店のかぶる時間帯の個数
    rep(i, n) {
      rep(j, zone) {
        if (f[i][j] == 1 and (bit>>j & 1)) ++c[i];
      }
    }

    ll sum = 0;
    rep(i, n) {
      sum += p[i][c[i]];
    }
    chmax(ans, sum);
  }

  cout << ans << '\n';
  return 0;
}