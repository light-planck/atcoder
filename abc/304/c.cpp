#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;
#include <atcoder/dsu>
using namespace atcoder;

int main() {
  ll N, D;
  cin >> N >> D;

  vector<ll> X(N), Y(N);
  rep(i, N) cin >> X[i] >> Y[i];

  dsu uf(N);
  rep(i, N) {
    rep(j, N) {
      if ((X[i] - X[j]) * (X[i] - X[j]) + (Y[i] - Y[j]) * (Y[i] - Y[j]) <=
          D * D) {
        uf.merge(i, j);
      }
    }
  }

  rep(i, N) {
    if (uf.same(i, 0))
      cout << "Yes" << '\n';
    else
      cout << "No" << '\n';
  }
  return 0;
}
