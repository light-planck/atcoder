#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n = 3;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];
  
  map<ll, ll> cnt;
  for (auto x : a) ++cnt[x];
  for (auto [x, c] : cnt) if (c == 1) cout << x << '\n';
  return 0;
}