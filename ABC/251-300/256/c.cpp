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

  vector<ll> h(3), w(3);
  rep(i, 3) cin >> h[i];
  rep(i, 3) cin >> w[i];

  ll ans = 0;
  for (ll a = 1; a <= 30; ++a) {
    for (ll b = 1; b <= 30; ++b) {
      for (ll c = 1; c <= 30; ++c) {
        for (ll d = 1; d <= 30; ++d) {
          if (h[0] - (a+b) <= 0) continue;
          if (h[1] - (c+d) <= 0) continue;
          if (w[0] - (a+c) <= 0) continue;
          if (w[1] - (b+d) <= 0) continue;
          ll x = w[2] - (h[0] - (a+b)) - (h[1] - (c+d));
          if (x <= 0) continue;
          ll y = w[0] - (a+c) + w[1] - (b+d);
          if (x + y != h[2]) continue;

          ++ans;
        }
      }
    }
  }

  cout << ans << "\n";
  return 0;
}