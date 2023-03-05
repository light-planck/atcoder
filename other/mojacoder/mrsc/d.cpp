#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  string s;
  cin >> s;

  map<char, ll> cnt_s;
  for (auto c : s) ++cnt_s[c];

  ll n;
  cin >> n;

  vector<string> t(n);
  rep(i, n) cin >> t[i];

  constexpr ll inf = 1ll << 60;
  ll ans = inf;
  for (ll bit = 0; bit < (1<<n); ++bit) {
    map<char, ll> cnt;
    ll bit_count = 0;
    rep(i, n) {
      if (bit>>i & 1) {
        for (auto c : t[i]) ++cnt[c];
        ++bit_count;
      }
    }

    bool ok = true;
    for (auto [c, num] : cnt_s) {
      if (cnt[c] < num) ok = false;
    }
    if (ok) ans = min(ans, bit_count);
  }

  if (ans == inf) cout << -1 << '\n';
  else cout << ans << '\n';
  return 0;
}