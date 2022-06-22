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
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;
// using mint = modint1000000007;


int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  ll n, k;
  cin >> n >> k;

  vector<ll> l(k), r(k);
  rep(i, k) cin >> l[i] >> r[i];

  vector<mint> dp(n + 1);
  dp[1] = 1;

  vector<mint> sum_dp(n + 1);
  sum_dp[1] = dp[1];

  for (ll i = 2; i <= n; ++i) {
    rep(j, k) {
      ll left = i - r[j];
      ll right = i - l[j];
      chmax(left, 0LL);
      chmax(right, 0LL);

      dp[i] += sum_dp[right] - sum_dp[left - 1];
    }

    sum_dp[i] += sum_dp[i - 1] + dp[i];
  }

  cout << dp[n].val() << "\n";
  return 0;
}