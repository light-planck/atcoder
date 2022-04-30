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


void greedy() {
  for (ll d = 0; d < D; ++d) {
    ll score = -2e18;
    ll type = 0;

    for (ll i = 0; i < TYPE; ++i) {
      ll tmp = last[i];
      last[i] = d;

      // 満足度の減少の計算
      ll sub_score = 0;
      for (ll j = 0; j < TYPE; ++j) {
        sub_score += c[j] * (d - last[j]);
      }

      // スコアの更新
      ll tmp_score = s[d][i] - sub_score;
      if (score < tmp_score) {
        score = tmp_score;
        type = i;
      }

      // lastを最初に戻す
      last[i] = tmp;
    }

    t[d] = type;
    last[type] = d;
  }
}


int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> D;
  rep(i, TYPE) cin >> c[i];
  rep(i, D) rep(j, TYPE) cin >> s[i][j];

  rep(i, TYPE) last[i] = -1;

  greedy();

  rep(i, D) cout << t[i] + 1 << "\n";
  return 0;
}