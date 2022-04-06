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


const ll inf = 1e9;
ll dist[410][410];

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  ll n, m;
  cin >> n >> m;

  rep(i, n) rep(j, n) {
    if (i == j) dist[i][j] = 0;
    else dist[i][j] = inf;
  }

  rep(i, m) {
    ll a, b, c;
    cin >> a >> b >> c;
    --a; --b;
    dist[a][b] = c;
  }

  ll ans = 0;
  rep(k, n) {
    rep(i, n) rep(j, n) {
      chmin(dist[i][j], dist[i][k] + dist[k][j]);
      if (dist[i][j] < inf) ans += dist[i][j];
    }
  }
  
  cout << ans << "\n";
  return 0;
}