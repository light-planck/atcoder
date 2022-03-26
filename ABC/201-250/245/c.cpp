#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(x) (x).begin(),(x).end()
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;
// using mint = modint1000000007;


int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  ll n, k;
  cin >> n >> k;

  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  vector<ll> b(n);
  rep(i, n) cin >> b[i];

  vector<vector<ll>> dp(n + 1, vector<ll>(2));
  dp[1][0] = a[0];
  dp[1][1] = b[0];

  for (int i = 1; i < n; ++i) {
    rep(j, 2) {
      rep(l, 2) {
        ll x;
        if (l == 0) x = a[i];
        else x = b[i];

        if (!dp[i][j]) continue;
        if (abs(dp[i][j] - x) <= k) {
          dp[i + 1][l] = x;
        }
      }
    }
  }

  if (dp[n][0] || dp[n][1]) cout << "Yes" << "\n";
  else cout << "No" << "\n";
  return 0;
}