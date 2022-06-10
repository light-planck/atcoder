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
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
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

  ll n, k;
  cin >> n >> k;

  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  ll log_k = (ll)log2(k) + 5;

  // db[j][i] a[i]の2^j個先
  vector<vector<ll>> db(log_k, vector<ll>(n));
  rep(i, n) db[0][i] = (i + a[i]) % n;

  vector<vector<ll>> cost(log_k, vector<ll>(n));
  rep(i, n) cost[0][i] = a[i];

  // dbテーブル
  rep(j, log_k - 1) rep(i, n) {
    db[j + 1][i] = db[j][db[j][i]];
    cost[j + 1][i] = cost[j][db[j][i]] + cost[j][i];
  }

  ll ans = 0;
  ll now = 0;
  rep(j, log_k - 1) {
    if (k == 0) break;

    if (k & 1) {
      ans += cost[j][now];
      now = db[j][now];
    }
    
    k >>= 1;
  }

  cout << ans << "\n";
  return 0;
}