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
// using mint = modint998244353;
// using mint = modint1000000007;


int op(int a, int b) {
  return a ^ b;
}


int e() {
  return 0;
}


int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int n, q;
  cin >> n >> q;

  segtree<int, op, e> seg(n);
  rep(i, n) {
    int a;
    cin >> a;
    seg.set(i, a);
  }

  while (q--) {
    int t, x, y;
    cin >> t >> x >> y;
    --x; --y;

    if (t == 1) {
      seg.set(x, seg.get(x) ^ (y + 1));
    }
    else {
      cout << seg.prod(x, y + 1) << "\n";
    }
  }
  return 0;
}