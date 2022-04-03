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
長方形を表す領域をx1 <= x <= x2, y1 <= y <= y2
とすると、長方形の頂点の座標は(x, y) = ((x1 or x2), (y1 or y2))
である。
3つの頂点のxとyの座標をカウントし、カウントが1の座標が求める座標である。
*/


int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  map<int, int> mp_x;
  map<int, int> mp_y;

  rep(i, 3) {
    int x, y;
    cin >> x >> y;
    ++mp_x[x];
    ++mp_y[y];
  }

  for (auto mp : mp_x) {
    if (mp.second == 1) {
      cout << mp.first << "\n";
    }
  }

  for (auto mp : mp_y) {
    if (mp.second == 1) {
      cout << mp.first << "\n";
    }
  }
  return 0;
}