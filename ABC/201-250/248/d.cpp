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

  ll n;
  cin >> n;

  vector<vector<ll>> a_idx(n + 1);
  rep(i, n) {
    ll a;
    cin >> a;
    a_idx[a].emplace_back(i);
  }

  ll q;
  cin >> q;

  while (q--) {
    ll l, r, x;
    cin >> l >> r >> x;
    --l; --r;

    if (a_idx[x].size()) {
      ll li = lower_bound(all(a_idx[x]), l) - a_idx[x].begin();
      ll ri = lower_bound(all(a_idx[x]), r + 1) - a_idx[x].begin();
      cout << ri - li << "\n";
    }
    else cout << 0 << "\n";
  }
  return 0;
}