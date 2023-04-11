#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n, c;
  cin >> n >> c;

  vector<ll> x(n), v(n);
  rep(i, n) cin >> x[i] >> v[i];

  // 最大値を保持
  vector<ll> max_value(n+1);
  for (ll i = 0; i < n; ++i) max_value[i+1] = max(max_value[i], max_value[i]+v[i]-x[i]);

  // valueの累積和
  vector<ll> sum_v(n+1);
  rep(i, n) sum_v[i+1] += sum_v[i] + v[i];

  ll ans = 0;
  {
    ll sum = 0;
    ll tmp = 0;
    rep(i, n) {
      sum += v[i]-x[i];
      tmp = max(tmp, sum);
    }
    ans = max(ans, tmp);

    sum = 0;
    tmp = 0;
    for (ll i = n-1; i >= 0; --i) {
      sum += v[i] - (c-x[i]);
      tmp = max(tmp, sum);
    }
    ans = max(ans, tmp);
  }

  // bを固定して最適なaを探す
  for (ll b = n-1; b >= 1; --b) {
    ll oa = max_value[b-1];
    ll ob = (sum_v[n]-sum_v[b]) - (c-x[b]);

    ll tmp = max(2*oa+ob, oa+2*ob);
    ans = max(ans, tmp);
  }

  cout << ans << '\n';
  return 0;
}