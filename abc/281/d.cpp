#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n, k, d;
  cin >> n >> k >> d;

  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  vector dp(k+1, vector<ll>(d, -1));
  dp[0][0] = 0;

  rep(i, n) {
    vector prev(k+1, vector<ll>(d, -1));
    swap(prev, dp);

    rep(j, k+1) {
      rep(l, d) {
        if (prev[j][l] == -1) continue;

        auto chmax = [](auto& a, auto b) { if (a < b) a = b; };
        chmax(dp[j][l], prev[j][l]);
        if (j+1 <= k) chmax(dp[j+1][(l+a[i]) % d], prev[j][l]+a[i]);
      }
    }
  }

  cout << dp[k][0] << '\n';
  return 0;
}