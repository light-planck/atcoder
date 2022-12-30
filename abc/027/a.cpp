#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  map<ll, ll> cnt;
  ll n = 3;
  rep(i, n) {
    ll a;
    cin >> a;
    ++cnt[a];
  }
  for (auto [a, c] : cnt) {
    if (c == 1) cout << a << '\n';
    if (c == 3) cout << a << '\n';
  }
  return 0;
}