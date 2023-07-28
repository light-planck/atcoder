#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n, m;
  cin >> n >> m;

  vector<string> c(n);
  rep(i, n) cin >> c[i];

  vector<string> d(m);
  rep(i, m) cin >> d[i];

  map<string, ll> price;
  rep(i, m+1) {
    ll p;
    cin >> p;
    if (i == 0) price["none"] = p;
    else price[d[i-1]] = p;
  }

  ll ans = 0;
  for (auto s : c) {
    if (price.count(s)) ans += price[s];
    else ans += price["none"];
  }
  cout << ans << '\n';
}