#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n;
  cin >> n;

  vector a(n, vector<ll>(n));
  rep(i, n) rep(j, n) cin >> a[i][j];

  vector b(n, vector<ll>(n));
  rep(i, n) rep(j, n) cin >> b[i][j];

  rep(i, 4) {
    auto c = a;
    rep(i, n) rep(j, n) {
      c[j][n-1-i] = a[i][j];
    }

    bool ok = true;
    rep(i, n) rep(j, n) {
      if (c[i][j] == 1) {
        if (b[i][j] == 0) ok = false;
      }
    }

    if (ok) {
      cout << "Yes" << '\n';
      return 0;
    }
    
    a = c;
  }

  cout << "No" << '\n';
  return 0;
}