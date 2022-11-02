#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n;
  cin >> n;

  ll max_a = 1e5;

  vector<ll> cnt(max_a);
  rep(i, n) {
    ll a;
    cin >> a;
    ++cnt[a];
  }

  ll ans = 0;
  auto chmax = [](auto& a, auto b) { if (a < b) a = b; };
  for (ll i = 0; i < max_a; ++i) {
    ll now = cnt[i];
    if (i-1 >= 0) now += cnt[i-1];
    if (i+1 < max_a) now += cnt[i+1]; 
    chmax(ans, now);
  }

  cout << ans << '\n';
  return 0;
}