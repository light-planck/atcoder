#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n, a;
  cin >> n >> a;

  vector<ll> x(n);
  rep(i, n) cin >> x[i];

  ll ans = 0;
  for (ll select = 1; select <= n; ++select) {
    ll max_sum = select * 50;

    // dp[k][l]: j番目まで見てk個選んだときの総和がlの場合の数
    vector dp(select+1, vector<ll>(max_sum+1));
    dp[0][0] = 1;

    rep(j, n) {
      vector prev(select+1, vector<ll>(max_sum+1));
      swap(prev, dp);

      for (ll choose = 0; choose <= select; ++choose) {
        for (ll sum = 0; sum <= max_sum; ++sum) {
          // 選ばない
          dp[choose][sum] += prev[choose][sum];

          // 選ぶ
          if (choose+1 <= select and sum+x[j] <= max_sum) {
            dp[choose+1][sum+x[j]] += prev[choose][sum];
          }
        }
      }
    }

    ans += dp[select][select*a];
  }

  cout << ans << '\n';
  return 0;
}