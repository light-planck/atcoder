#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <deque>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  string s;
  cin >> s;

  string t;
  cin >> t;

  ll n = s.size();
  ll m = t.size();

  vector dp(n+1, vector<ll>(m+1));
  rep(i, n) rep(j, m) {
    auto chmax = [](auto& a, auto b) { if (a < b) a = b; };

    chmax(dp[i+1][j+1], dp[i][j+1]);
    chmax(dp[i+1][j+1], dp[i+1][j]);
    if (s[i] == t[j]) chmax(dp[i+1][j+1], dp[i][j]+1);
  }

  string ans;
  ll i = n; ll j = m;
  while (i > 0 and j > 0) {
    if (dp[i][j] == dp[i-1][j]) --i;
    else if (dp[i][j] == dp[i][j-1]) --j;
    else {
      ans += s[i-1];
      --i; --j;
    }
  }

  reverse(ans.begin(), ans.end());
  cout << ans << '\n';
  return 0;
}