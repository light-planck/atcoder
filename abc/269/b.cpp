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
  ll n = 10;

  vector<string> s(n);
  rep(i, n) cin >> s[i];

  rep(a, n) rep(b, n) rep(c, n) rep(d, n) {
    bool ok = true;

    rep(i, n) rep(j, n) {
      if ((a <= i and i <= b) and (c <= j and j <= d)) {
        if (s[i][j] == '.') ok = false;
      }
      else if (s[i][j] == '#') ok = false;
    }

    if (ok) {
      cout << a+1 << " " << b+1 << '\n';
      cout << c+1 << " " << d+1 << '\n';
      return 0;
    }
  }
  return 0;
}