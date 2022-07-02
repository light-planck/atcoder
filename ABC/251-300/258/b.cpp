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


const ll di[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const ll dj[] = {0, 1, 1, 1, 0, -1, -1, -1};

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  ll n;
  cin >> n;

  vector<string> a(n);
  rep(i, n) cin >> a[i];

  ll ans = 0;

  auto dfs = [&](auto dfs, ll ii, ll jj, ll cnt, ll move, string res) -> void {
    if (cnt == n) {
      chmax(ans, stoll(res));
      return;
    }

    ll ni = ii + di[move];
    ll nj = jj + dj[move];
    ni += n;
    nj += n;
    ni %= n;
    nj %= n;

    res += a[ni][nj];

    dfs(dfs, ni, nj, cnt+1, move, res);
  };

  rep(i, n) rep(j, n) {
    rep(k, 8) {
      string s;
      ll x = 0;

      dfs(dfs, i, j, x, k, s);
    }
  }

  cout << ans << "\n";
  return 0;
}