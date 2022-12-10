#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


ll dp[110][110][100];

int main() {
  ll n, k, d;
  cin >> n >> k >> d;

  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  rep(i, n) {
    rep(j, k) {
      rep(l, d) {
        dp[i+1][j][l] 
      }
    }
  }
  return 0;
}