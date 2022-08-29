#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <deque>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }


int main() {
  ll n;
  cin >> n;

  using P = pair<ll, ll>;
  map<P, ll> txa;
  ll max_t = 0;
  rep(i, n) {
    ll t, x, a;
    cin >> t >> x >> a;
    txa[{t, x}] = a;
    chmax(max_t, t);
  }

  // dp[i][j]: i=tでx=jにいるとき、これまで得られたすぬけの大きさの合計の最大値
  ll m = 5;
  vector<ll> dp(m, -1);
  dp[0] = 0;

  rep(i, max_t) {
    vector<ll> prev(m, -1);
    swap(prev, dp);

    rep(j, m) {
      if (prev[j] == -1) continue;

      for (ll nj = j-1; nj <= j+1; ++nj) {
        if (nj < 0 or nj >= m) continue;

        if (not txa.count({i+1, nj})) chmax(dp[nj], prev[j]);
        else {
          auto a = txa[{i+1, nj}];
          chmax(dp[nj], prev[j]+a);
        }
      }
    }
  }

  ll ans = *max_element(dp.begin(), dp.end());
  cout << ans << '\n';
  return 0;
}