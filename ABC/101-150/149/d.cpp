#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdint>
#include <deque>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
#define rng(a) (a).begin(),(a).end()
#define rrng(a) (a).rbegin(),(a).rend()
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

  ll n, k;
  cin >> n >> k;

  ll r, s, p;
  cin >> r >> s >> p;

  string t;
  cin >> t;

  auto score = [&](ll idx) {
    if (t[idx] == 'r') return p;
    if (t[idx] == 's') return r;
    else return s;
  };

  ll ans = 0;
  rep(ik, k) {
    bool win = false;

    for (ll i = ik; i < n; i += k) {

      // ロボットが前回と同じ手を出すとき
      if (i - k >= 0 and t[i] == t[i - k]) {
        
        // 前回負けたら今回は勝てる
        if (not win) {
          ans += score(i);
          win = true;
        }
        
        // 前回勝ったら今回は負ける
        else win = false;
      }
      // 異なる手なら絶対勝てる
      else {
        ans += score(i);
        win = true;
      }
    }
  }

  cout << ans << "\n";
  return 0;
}