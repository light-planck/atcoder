#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n;
  cin >> n;

  map<ll, ll> mp;
  rep(i, n) {
    ll a;
    cin >> a;
    ++mp[a];
  }

  ll ans = 0;
  auto chmax = [](auto& a, auto b) { if (a < b) a = b; };

  vector<ll> b;
  for (auto [a, c] : mp) {
    if (c >= 4) chmax(ans, a*a);
    if (c >= 2) b.emplace_back(a);
  }
  sort(b.rbegin(), b.rend());

  if (b.size() >= 2) chmax(ans, b[0]*b[1]);
  cout << ans << '\n';
  return 0;
}