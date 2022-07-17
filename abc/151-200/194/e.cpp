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


/*
制約をしっかり読んでるか
aの値でなくmexの値に着目できるか

mex = 0となるときは

0となるaが複数個存在するとき
ai = aj = 0となるようなi, j(i < j)が存在し
j - i >= m + 1のときである。

0となるaが唯一存在するとき
ai = 0とすると
左端からi、iから右端までの長さがm+1以上のときである。
*/


int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  ll n, m;
  cin >> n >> m;

  vector<vector<ll>> a_idx(n);
  rep(i, n) {
    ll a;
    cin >> a;
    a_idx[a].emplace_back(i);
  }

  for (ll mex = 0; mex < n; ++mex) {
    a_idx[mex].emplace_back(n);
    ll prev = -1;

    for (auto next : a_idx[mex]) {
      if (next - prev >= m + 1) {
        cout << mex << "\n";
        return 0;
      }

      prev = next;
    }
  }

  cout << n << "\n";
  return 0;
}