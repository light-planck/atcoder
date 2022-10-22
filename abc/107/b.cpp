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

  vector<bool> row(h, true);
  vector<bool> col(w, true);
  rep(i, h) {
    rep(j, w) {
      if (a[i][j] == '#') {
        row[i] = false;
        col[j] = false;
      }
    }
  }

  rep(i, h) {
    if (row[i]) continue;

    rep(j, w) {
      if (col[j]) continue;
      cout << a[i][j];
    }
    cout << '\n';
  }
  return 0;
}