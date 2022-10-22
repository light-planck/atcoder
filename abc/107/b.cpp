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

  vector<string> a(h);
  rep(i, h) cin >> a[i];

  vector<string> b(w);
  rep(j, w) {
    string col = "";
    rep(i, h) col += a[i][j];
    b[j] = col;
  }

  // 行
  set<ll> rows;
  string row = string(w, '.');
  rep(i, h) {
    if (a[i] == row) rows.emplace(i);
  }

  // 列
  set<ll> cols;
  string col = string(h, '.');
  rep(j, w) {
    if (b[j] == col) cols.emplace(j);
  }

  rep(i, h) {
    rep(j, w) {
      if (rows.count(i)) continue;
      if (cols.count(j)) continue;
      cout << a[i][j];
    }
    cout << '\n';
  }
  return 0;
}