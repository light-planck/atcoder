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


// c問題
ll m;
ll rd[100010];
ll q[100010];


// d日目にコンテストiを選んだときのスコア
ll compute_day_score(ll d, ll i) {
  ll score = s[d][i];
  last[i] = d;

  for (ll j = 0; j < TYPE; ++j) {
    score -= c[j] * (d - last[j]);
  }

  return score;
}


ll compute_score() {
  ll score = 0;

  for (ll d = 0; d < D; ++d) {
    score += compute_day_score(d, t[d]);  
  }

  return score;
}


void greedy() {
  ll score = 0;

  for (ll d = 0; d < D; ++d) {
    ll max_score = -2e18;
    ll type = 0;

    for (ll i = 0; i < TYPE; ++i) {
      ll tmp = last[i];
      last[i] = d;

      ll now_score = compute_day_score(d, i);

      // スコアの更新
      if (max_score < now_score) {
        max_score = now_score;
        type = i;
      }

      // lastを最初に戻す
      last[i] = tmp;
    }

    t[d] = type;
    last[type] = d;
    score += max_score;
  }
}


void input() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> D;
  rep(i, TYPE) cin >> c[i];
  rep(i, D) rep(j, TYPE) cin >> s[i][j];
}


void init() {
  rep(i, TYPE) last[i] = -1;
}


void output() {
  rep(i, D) cout << t[i] + 1 << "\n";
}


int main() {
  input();
  init();

  greedy();

  output();
  return 0;
}