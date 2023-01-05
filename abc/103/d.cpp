#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n, m;
  cin >> n >> m;

  vector<pair<ll, ll>> lr;
  rep(i, m) {
    ll a, b;
    cin >> a >> b;
    lr.emplace_back(a, b);
  }
  sort(lr.begin(), lr.end(), [](pair<ll, ll> a, pair<ll, ll> b){ return a.second < b.second; });

  ll ans = 0;
  ll stop = 0;
  for (auto [left, right] : lr) {
    if (left >= stop) {
      stop = right;
      ++ans;
    }
  }

  cout << ans << '\n';
  return 0;
}