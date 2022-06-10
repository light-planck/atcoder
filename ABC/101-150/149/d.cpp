#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;

const int kInf = 1e9;

bool win(string& t, int day, int hand) {
  if (t[day] == 'r' && hand == 2) return true;
  else if (t[day] == 's' && hand == 0) return true;
  else if (t[day] == 'p' && hand == 1) return true;
  else return false;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  ll n, k;
  cin >> n >> k;

  ll r, s, p;
  vector<ll> point(3);
  rep(i, 3) cin >> point[i];

  string t;
  cin >> t;

  // dp[i][j] i日目にjの手を出したときの
  // それまでの点数の合計の最大値
  vector<vector<ll>> dp(n + 1, vector<ll>(3));
  rep(i, n) {
    if (i - k < 0) continue;

    // i - k日目に手jを出した
    rep(j, 3) {
      rep(l, 3) {
        if (j == l) continue;

        if (win(t, i, l)) {
          dp[i][l] = dp[i - k][j] + point[l];
        }
        else {
          dp[i][l] = dp[i - k][j];
        }
      }
    }
  }

  ll ans = 0;
  rep(i, 3) ans = max(ans, dp[n - 1][i]);
  cout << ans << "\n";
  return 0;
}