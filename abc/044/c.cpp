#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  // ll n, a;
  // cin >> n >> a;

  // rep(l, n) {
  //   ll lim = n * 50;
  //   vector dp(n+1, vector<vector<ll>>(l+1, vector<ll>(lim)));
  // }

  vector dp(1, vector<vector<ll>>(1, vector<ll>(1)));
  dp[0][0][0] = 100;
  cout << dp[0][0][0] << '\n';
  return 0;
}