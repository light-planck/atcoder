#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <deque>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n, m;
  cin >> n >> m;

  using P = pair<ll, ll>;
  vector<P> dij;
  for (ll di = -n; di <= n; ++di) {
    for (ll dj = -n; dj <= n; ++dj) {
      if (di*di + dj*dj == m) dij.emplace_back(di, dj);
    }
  }

  vector dist(n, vector<ll>(n, -1));
  dist[0][0] = 0;

  deque<P> que;
  que.emplace_back(0, 0);

  while (not que.empty()) {
    auto [i, j] = que.front(); que.pop_front();

    for (auto [di, dj] : dij) {
      ll ni = i + di; ll nj = j + dj;
      if (ni < 0 or ni >= n) continue;
      if (nj < 0 or nj >= n) continue;
      if (dist[ni][nj] != -1) continue;

      dist[ni][nj] = dist[i][j] + 1;
      que.emplace_back(ni, nj);
    }
  }

  rep(i, n) rep(j, n) cout << dist[i][j] << '\n';
  return 0;
}