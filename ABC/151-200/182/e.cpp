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

  vector<vector<int>> grid(h, vector<int>(w));

  // light
  rep(i, n) {
    ll a, b;
    cin >> a >> b;
    --a; --b;
    grid[a][b] = 1;
  }

  // wall
  rep(i, m) {
    ll a, b;
    cin >> a >> b;
    --a; --b;
    grid[a][b] = 2;
  }

  // 光が届いたか
  vector<vector<bool>> lighten(h, vector<bool>(w));

  vector<vector<int>> tmp;

  // 下
  tmp = grid;
  for (int j = 0; j < w; ++j) {
    for (int i = 0; i < h; ++i) {
      if (tmp[i][j] == 2) continue;

      if (i - 1 >= 0 && tmp[i - 1][j] == 1) {
        tmp[i][j] = 1;
      }

      if (tmp[i][j] == 1) {
        lighten[i][j] = true;
      }
    }
  }

  // 上
  tmp = grid;
  for (int j = 0; j < w; ++j) {
    for (int i = h-1; i >= 0; --i) {
      if (tmp[i][j] == 2) continue;

      if (i + 1 < h && tmp[i + 1][j] == 1) {
        tmp[i][j] = 1;
      }

      if (tmp[i][j] == 1) {
        lighten[i][j] = true;
      }
    }
  }

  // 右
  tmp = grid;
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      if (tmp[i][j] == 2) continue;

      if (j - 1 >= 0 && tmp[i][j - 1] == 1) {
        tmp[i][j] = 1;
      }

      if (tmp[i][j] == 1) {
        lighten[i][j] = true;
      }
    }
  }

  // 左
  tmp = grid;
  for (int i = 0; i < h; ++i) {
    for (int j = w - 1; j >= 0; --j) {
      if (tmp[i][j] == 2) continue;

      if (j + 1 < w && tmp[i][j + 1] == 1) {
        tmp[i][j] = 1;
      }

      if (tmp[i][j] == 1) {
        lighten[i][j] = true;
      }
    }
  }

  ll ans = 0;
  rep(i, h) rep(j, w) {
    if (lighten[i][j]) ++ans;
  }

  cout << ans << "\n";
  return 0;
}