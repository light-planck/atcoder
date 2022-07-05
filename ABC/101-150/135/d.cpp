#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdint>
#include <deque>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
#define rng(a) (a).begin(),(a).end()
#define rrng(a) (a).rbegin(),(a).rend()
using namespace std;
using ll = long long;
using P = pair<long long, long long>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
#include <atcoder/all>
using namespace atcoder;
// using mint = modint998244353;
using mint = modint1000000007;


int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  string s;
  cin >> s;

  ll n = s.size();

  vector dp(n+1, vector<mint>(13));
  dp[0][0] = 1;

  rep(i, n) {
    rep(j, 13) {
      if (s[i] == '?') {
        rep(d, 10) {
          dp[i + 1][(10*j+d) % 13] += dp[i][j];
        }
      }
      else {
        ll d = s[i] - '0';
        dp[i + 1][(10*j+d) % 13] += dp[i][j];
      }
    }
  }

  cout << dp[n][5].val() << "\n";
  return 0;
}