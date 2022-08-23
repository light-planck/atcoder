#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n, k;
  cin >> n >> k;

  vector<ll> cnt(k);
  for (ll i = 1; i <= n; ++i) ++cnt[i % k];

  ll ans = 0;
  for (ll a = 0; a < k; ++a) {
    ll b = (k-a) % k;
    ll c = (k-a) % k;
    if ((b+c) % k != 0) continue;
    ans += cnt[a] * cnt[b] * cnt[c];
  }

  cout << ans << '\n';
  return 0;
}