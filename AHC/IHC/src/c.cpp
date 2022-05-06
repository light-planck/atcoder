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


void init_last() {
  rep(i, TYPE) last[i] = -1;
}


// d日目にコンテストt[d]を選んだときのスコア
ll compute_day_score(ll d) {
  ll day_score = s[d][t[d]];
  last[t[d]] = d;

  for (ll i = 0; i < TYPE; ++i) {
    day_score -= c[i] * (d - last[i]);
  }

  return day_score;
}


ll compute_score() {
  ll score = 0;

  init_last();

  for (ll d = 0; d < D; ++d) {
    score += compute_day_score(d);  
  }

  return score;
}


void solve_c() {
  rep(i, D) {
    cin >> t[i];
    --t[i];
  }

  ll m;
  cin >> m;

  rep(i, m) {
    ll d, q;
    cin >> d >> q;
    --d; --q;

    t[d] = q;

    ll score = compute_score();
    cout << score << "\n";
  }
}


void input() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> D;
  rep(i, TYPE) cin >> c[i];
  rep(i, D) rep(j, TYPE) cin >> s[i][j];
}


void output() {
  rep(i, D) cout << t[i] + 1 << "\n";
}


int main() {
  input();

  solve_c();

  // output();
  return 0;
}