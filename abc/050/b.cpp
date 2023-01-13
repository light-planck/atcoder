#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  ll n;
  cin >> n;

  vector<ll> t(n);
  rep(i, n) cin >> t[i];

  ll m;
  cin >> m;

  ll sum = accumulate(t.begin(), t.end(), 0ll);
  rep(i, m) {
    ll p, x;
    cin >> p >> x;
    --p;
    
    ll ans = sum - t[p] + x;
    cout << ans << '\n';
  }
  return 0;
}