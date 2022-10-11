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

  vector<string> a(n);
  rep(i, n) cin >> a[i];

  vector<string> b(m);
  rep(i, m) cin >> b[i];

  rep(i, n) rep(j, n) {
    if (i+m > n) continue;
    if (j+m > n) continue;

    bool ok = true;
    rep(k, m) rep(l, m) {
      if (a[i+k][j+l] != b[k][l]) ok = false;
    }

    if (ok) {
      cout << "Yes" << '\n';
      return 0;
    }
  }

  cout << "No" << '\n';
  return 0;
}