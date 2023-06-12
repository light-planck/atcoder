#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;

int main() {
  ll n, m;
  cin >> n >> m;

  vector familiar(n, vector<bool>(n));
  rep(i, m) {
    vector<ll> a(n);
    rep(j, n) cin >> a[j];
    rep(j, n) a[j]--;

    rep(j, n - 1) {
      familiar[a[j]][a[j + 1]] = true;
      familiar[a[j + 1]][a[j]] = true;
    }
  }

  ll ans = 0;
  rep(i, n) rep(j, n) {
    if (i == j)
      continue;
    if (not familiar[i][j])
      ++ans;
  }

  cout << ans / 2 << '\n';
  return 0;
}
