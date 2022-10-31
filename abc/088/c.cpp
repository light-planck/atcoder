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
  ll n = 3;

  vector c(n, vector<ll>(n));
  rep(i, n) rep(j, n) cin >> c[i][j];

  for (ll a0 = 0; a0 <= 100; ++a0) {
    for (ll a1 = 0; a1 <= 100; ++a1) {
      for (ll a2 = 0; a2 <= 100; ++a2) {
        vector<ll> a = {a0, a1, a2};
        vector<bool> seen_b(n, false);
        vector<ll> b(n);
        bool ok = true;

        [&] {
          rep(i, n) rep(j, n) {
            if (not seen_b[j]) {
              b[j] = c[i][j] - a[i];
              seen_b[j] = true;
            }
            else {
              if (b[j] != c[i][j] - a[i]) {
                ok = false;
                return;
              }
            }
          }
        } ();

        if (ok) {
          cout << "Yes" << '\n';
          return 0;
        }
      }
    }
  }

  cout << "No" << '\n';
  return 0;
}