#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n, m;
  cin >> n >> m;

  vector<pair<ll, ll>> lc;
  rep(_, m) {
    ll l, c;
    cin >> l >> c;
    lc.emplace_back(l, c);
  }
  sort(lc.begin(), lc.end());

  ll now = 0;
  for (auto [l, c] : lc) {
    if (now <= l) now = l + c;
    else now += c;
  }

  cout << now - 1 << '\n';
  return 0;
}