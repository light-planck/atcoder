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


ll calc_score() {
  ll score = 0;

  for (ll d = 0; d < D; ++d) {
    ll type = t[d];
    score += s[d][type];

    last[type] = d;
    for (ll i = 0; i < TYPE; ++i) {
      score -= c[i] * (d - last[i]);
    }

    cout << score << "\n";
  }

  return score;
}


int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> D;
  rep(i, TYPE) cin >> c[i];
  rep(i, D) rep(j, TYPE) cin >> s[i][j];
  rep(i, D) {
    cin >> t[i];
    --t[i];
  }
  fill(last, last + TYPE, -1);

  ll score = calc_score();
  cout << score << "\n";
  return 0;
}