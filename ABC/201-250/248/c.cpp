#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower
#include <cmath> // abs, sqrt, cos, ...
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(x) (x).begin(),(x).end()
using namespace std;
using ll = long long;
using P = pair<long long, long long>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;
// using mint = modint1000000007;


// dp[i][j]
// 数列aのi番目までの和がjで、条件を満たす
// 場合の数
mint dp[55][3000];


int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  ll n, m, k;
  cin >> n >> m >> k;

  dp[0][0] = 1;

  // rep(i, n) {
  //   rep(j, k + 1) {
  //     rep(ai, m+1) {
  //       if (j - ai >= 0) {
  //         dp[i + 1][j] += dp[i][j - ai];
  //       }
  //     }
  //   }
  // }

  for (int i = 0; i < n; ++i) {
    for (int j = 1; j <= k; ++j) {
      for (int ai = 1; ai <= m; ++ai) {
        if (j - ai >= 0) {
          dp[i + 1][j] += dp[i][j - ai];
        }
      }
    }
  }

  mint ans = 0;
  rep(j, k + 1) ans += dp[n][j];
  cout << ans.val() << "\n";
  return 0;
}