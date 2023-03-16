#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n;
  cin >> n;

  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  ll m;
  cin >> m;

  vector<ll> b(m);
  rep(i, m) cin >> b[i];

  ll x;
  cin >> x;

  vector<ll> dp(x+1);
  dp[0] = 1;
  rep(i, m) dp[b[i]] = -1;

  rep(i, x+1) {
    if (dp[i] != 1) continue;
    
    rep(j, n) {
      ll k = i + a[j];
      if (k > x or dp[k] == -1) continue;
      dp[k] = true;
    }
  }

  if (dp[x]) cout << "Yes" << '\n';
  else cout << "No" << '\n';
  return 0;
}