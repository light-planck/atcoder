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


int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  ll n, m;
  cin >> n >> m;

  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  vector<vector<ll>> edges(n);
  while (m--) {
    ll x, y;
    cin >> x >> y;
    --x; --y;
    edges[x].emplace_back(y);
  }

  const ll inf = 2e18;
  vector<ll> dp(n, inf);

  ll ans = -inf;
  rep(i, n) {

    // dp[i]: i以前の購入価格の最小値
    // iで売却したら答えはa[i] - dp[i]
    chmax(ans, a[i] - dp[i]);

    // iの隣接頂点to
    // to以前の購入価格の最小値はdp[i], a[i], dp[to]の最小値
    for (auto to : edges[i]) {
      dp[to] = min({dp[to], dp[i], a[i]});
    }
  }

  cout << ans << "\n";
  return 0;
}