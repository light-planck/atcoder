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


int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  ll n;
  cin >> n;

  vector<ll> a(n), b(n);
  rep(i, n) cin >> a[i] >> b[i];

  set<ll> sa, sb;

  set<P> ans;

  // iを固定
  for (ll i = 0; i < n; ++i) {

    // jを動かす
    
    for (ll j = 0; j < n; ++j) {
      if (a[i] != b[j]) {
        sa.insert(a[i]);
        sb.insert(b[j]);
        break;
      }
      else {
        ans.insert({i, j});
      }

      // 集合が一致していたら(i, j)を記録

      // しなかったらiを動かす
      
    }
  }
  

  ll q;
  cin >> q;

  while (q--) {
    ll x, y;
    cin >> x >> y;
    --x; --y;
    if (ans.count({x, y})) {
      cout << "Yes" << "\n";
    }
    else cout << "No" << "\n";
  }
  return 0;
}