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
#include <unordered_map>
#include <unordered_set>
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
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;


double dp[101][101][101];


int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  ll a, b, c;
  cin >> a >> b >> c;

  for (ll i = 99; i >= 0; --i) {
    for (ll j = 99; j >= 0; --j) {
      for (ll k = 99; k >= 0; --k) {
        if (i+j+k == 0) continue;

        dp[i][j][k] += i * (dp[i + 1][j][k]+1);
        dp[i][j][k] += j * (dp[i][j + 1][k]+1);
        dp[i][j][k] += k * (dp[i][j][k + 1]+1);
        dp[i][j][k] /= i + j + k;
      }
    }
  }

  printf("%.10f\n", dp[a][b][c]);
  return 0;
}