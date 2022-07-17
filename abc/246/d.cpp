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


ll f(ll a, ll b) {
  return a*a*a + a*a*b + a*b*b + b*b*b;
}


int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  ll n;
  cin >> n;

  const ll max_ab = 1e6;
  ll ans = 1e18 + 10;
  for (int i = 0; i <= max_ab; ++i) {
    
    // aを固定したときのx = b^3 + ab^2 +...
    // がn以上となる最小のbを求める

    // 二分探索：x = f(b) >= nとなるbの境界を求める
    ll ng = -1; // x = -1のとき必ずx >= nとならない
    ll ok = max_ab + 1; // x = max_ab + 1のとき必ずx >= nとなる

    while (abs(ok - ng) > 1) {
      ll mid = (ok + ng) / 2;
      if (f(i, mid) >= n) ok = mid;
      else ng = mid;
    }

    chmin(ans, f(i, ok));
  }

  cout << ans << "\n";
  return 0;
}