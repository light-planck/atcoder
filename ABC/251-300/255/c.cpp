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

  ll x, a, d, n;
  cin >> x >> a >> d >> n;

  bool dec = false;
  if (d < 0) dec = true;

  ll ok = n;
  ll ng = -1;
  if (dec) swap(ok, ng);

  auto s = [&](ll t) -> ll {
    return a + t*d;
  };

  // x以上の範囲を見つける
  while (abs(ok - ng) > 1) {
    ll mid = (ok + ng) / 2;
    if (s(mid) >= x) ok = mid;
    else ng = mid;
  }

  // sにx以上の範囲が含まれなかった場合
  if (dec and ok == -1) ok = 0;
  if (not dec and ok == n) ok = n - 1;

  ll ans = abs(s(ok) - x);
  if (ok - 1 >= 0) chmin(ans, abs(s(ok-1) - x));
  if (ok + 1 < n) chmin(ans, abs(s(ok+1) - x));
  cout << ans << "\n";
  return 0;
}