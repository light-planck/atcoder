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
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;


int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  ll h, w, n, m;
  cin >> h >> w >> n >> m;

  set<ll> light_i;
  set<ll> light_j;
  rep(i, n) {
    ll a, b;
    cin >> a >> b;
    --a; --b;
    light_i.insert(a);
    light_j.insert(b);
  }

  set<pair<ll, ll>> wall;
  rep(i, m) {
    ll c, d;
    cin >> c >> d;
    --c; --d;
    wall.insert({c, d});
  }

  ll ans = 0;
  rep(i, h) rep(j, w) {
    // 壁ならスキップ
    if (wall.count({i, j})) continue;

    // (a, b)の
    if (light_i.count(i) || light_j.count(j)) ++ans;
  }

  cout << ans << "\n";
  return 0;
}