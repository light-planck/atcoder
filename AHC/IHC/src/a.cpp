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


const ll TYPE = 26;
ll D;
ll c[TYPE];
ll s[400][TYPE];
ll t[400];
ll last[TYPE];


ll decrease_score(ll d) {
  ll res = 0;

  for (ll i = 0; i < TYPE; ++i) {
    res += c[i] * (d - last[i]);
  }

  return res;
}


ll choose_next(ll d) {
  ll max_s = -1e18;

  ll type = 0;
  for (ll j = 0; j < TYPE; ++j) {
    if (max_s < s[d][j]) {
      type = j;
    }
  }

  return type;
}


ll compute_score() {
  ll score = 0;

  for (ll d = 0; d < D; ++d) {
    ll type = t[d];
    score += s[d][type];

    last[type] = d;

    score -= decrease_score(d);

    // 次のコンテストはs[d+1][j]が最大のjを選ぶ
    t[d + 1] = choose_next(d + 1);
  }

  return score;
}


int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> D;
  rep(i, TYPE) cin >> c[i];
  rep(i, D) rep(j, TYPE) cin >> s[i][j];
  fill(last, last + TYPE, -1);

  // 初日は係数cが大きい種類のコンテストを開催する
  t[0] = choose_next(0);

  ll score = compute_score();

  rep(i, D) cout << t[i] << "\n";
  return 0;
}