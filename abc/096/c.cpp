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
  ll h, w;
  cin >> h >> w;

  vector<string> s(h);
  rep(i, h) cin >> s[i];

  vector<pair<ll, ll>> dij = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
  
  rep(i, h) rep(j, w) {
    if (s[i][j] == '.') continue;
    bool ok = false;

    for (auto [di, dj] : dij) {
      ll ni = i + di;
      ll nj = j + dj;

      if (ni < 0 or ni >= h) continue;
      if (nj < 0 or nj >= w) continue;

      if (s[ni][nj] == '#') ok = true;
    }

    if (not ok) {
      cout << "No" << '\n';
      return 0;
    }
  }

  cout << "Yes" << '\n';
  return 0;
}