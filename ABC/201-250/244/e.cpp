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
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;
// using mint = modint1000000007;


// dp[i][j][l]: 頂点sからi回移動したとき頂点jに達するような場合の数
// l: (xを通った回数) % 2
mint dp[2010][2010][2];

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  ll n, m, k, s, t, x;
  cin >> n >> m >> k >> s >> t >> x;
  --s; --t; --x;

  vector<vector<ll>> edge(n);
  rep(i, m) {
    ll u, v;
    cin >> u >> v;
    --u; --v;
    edge[u].emplace_back(v);
    edge[v].emplace_back(u);
  }

  // dpの初期化
  dp[0][s][0] = 1;

  rep(i, k) {
    rep(j, n) {
      for (auto to : edge[j]) {
        if (to == x) {
          dp[i + 1][to][0] += dp[i][j][1];
          dp[i + 1][to][1] += dp[i][j][0];
        }
        else {
          dp[i + 1][to][0] += dp[i][j][0];
          dp[i + 1][to][1] += dp[i][j][1];
        }
      }
    }
  }

  cout << dp[k][t][0].val() << "\n";
  return 0;
}