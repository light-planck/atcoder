#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n, c;
  cin >> n >> c;

  ll limit = 100000;
  vector imos(c, vector<ll>(limit));
  rep(i, n) {
    ll s, t, c;
    cin >> s >> t >> c;
    --s; --t; --c;
    ++imos[c][s];
    --imos[c][t+1];
  }

  rep(i, c) {
    rep(j, limit-1) {
      imos[i][j+1] += imos[i][j];
    }
  }

  ll ans = 0;
  rep(t, limit) {
    ll cnt = 0;
    rep(i, c) {
      if (imos[i][t]) ++cnt;
    }
    
    auto chmax = [](auto& a, auto b) { if (a < b) a = b; };
    chmax(ans, cnt);
  }

  cout << ans << '\n';
  return 0;
}