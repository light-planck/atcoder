#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdint>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
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


struct Light {
  ll up = 0;
  ll down = 0;
  ll left = 0;
  ll right = 0;
};


int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  bool debug = 0;

  ll h, w;
  cin >> h >> w;

  vector<string> s(h);
  rep(i, h) cin >> s[i];

  vector<vector<Light>> light(h, vector<Light>(w));

  // 左方向に照らすことのできるマスの個数
  for (ll i = 0; i < h; ++i) {
    ll l = 0;

    for (ll j = w-1; j >= 0; j--) {
      if (s[i][j] == '#') {
        l = 0;
        continue;
      }

      light[i][j].left = l;
      ++l;
    }
  }

  // 右方向に照らすことのできるマスの個数
  for (ll i = 0; i < h; ++i) {
    ll r = 0;

    for (ll j = 0; j < w; ++j) {
      if (s[i][j] == '#') {
        r = 0;
        continue;
      }

      light[i][j].right = r;
      ++r;
    }
  }

  // 下方向に照らすことのできるマスの個数
  for (ll j = 0; j < w; ++j) {
    ll d = 0;

    for (ll i = h-1; i >= 0; --i) {
      if (s[i][j] == '#') {
        d = 0;
        continue;
      }

      light[i][j].down = d;
      ++d;
    }
  }

  // 上方向に照らすことのできるマスの個数
  for (ll j = 0; j < w; ++j) {
    ll u = 0;

    for (ll i = 0; i < h; ++i) {
      if (s[i][j] == '#') {
        u = 0;
        continue;
      }

      light[i][j].up = u;
      ++u;
    }
  }

  ll ans = 0;
  rep(i, h) rep(j, w) {
    if (s[i][j] == '#') continue;

    ll sum = light[i][j].up + light[i][j].down + light[i][j].left + light[i][j].right + 1;
    chmax(ans, sum);
  }

  cout << ans << "\n";
  return 0;
}