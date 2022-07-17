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


const int di[] = {1, 0, -1, 0};
const int dj[] = {0, 1,  0, -1};


int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  ll h, w;
  cin >> h >> w;

  vector<ll> c(2);
    rep(i, 2) {
    cin >> c[i];
    --c[i];
  }

  vector<ll> d(2);
  rep(i, 2) {
    cin >> d[i];
    --d[i];
  }

  vector<string> s(h);
  rep(i, h) cin >> s[i];

  const ll inf = 1e18;
  vector<vector<ll>> dist(h, vector<ll>(w, inf));
  dist[c[0]][c[1]] = 0;

  deque<P> deq;
  deq.emplace_back(c[0], c[1]);

  while (!deq.empty()) {
    auto [i, j] = deq.front();
    deq.pop_front();
    ll d = dist[i][j];

    // 魔法を使わない
    rep(k, 4) {
      ll ni = i + di[k]; ll nj = j + dj[k];

      if (ni < 0 or ni >= h or nj < 0 or nj >= w) continue;
      if (s[ni][nj] == '#') continue;
      if (dist[ni][nj] <= d) continue;

      dist[ni][nj] = d;
      deq.emplace_front(ni, nj);
    }

    // 使う
    for (ll k = -2; k <= 2; ++k) {
      for (ll l = -2; l <= 2; ++l) {
        ll ni = i + k; ll nj = j + l;
        
        if (ni < 0 or ni >= h or nj < 0 or nj >= w) continue;
        if (s[ni][nj] == '#') continue;
        if (dist[ni][nj] <= d+1) continue;
        
        dist[ni][nj] = d+1;
        deq.emplace_back(ni, nj);
      }
    }
  }

  ll ans = dist[d[0]][d[1]];
  if (ans == inf) ans = -1;
  cout << ans << "\n";
  return 0;
}