#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;

int main() {
  const ll N = 9;

  vector A(N, vector<ll>(N));
  rep(i, N) rep(j, N) cin >> A[i][j];

  vector<ll> b(N);
  iota(b.begin(), b.end(), 1);

  // 列
  rep(j, N) {
    vector<ll> c;
    rep(i, N) { c.emplace_back(A[i][j]); }
    sort(c.begin(), c.end());

    if (c != b) {
      cout << "No" << endl;
      exit(0);
    }
  }

  // 縦
  rep(i, N) {
    vector<ll> c;
    rep(j, N) { c.emplace_back(A[i][j]); }
    sort(c.begin(), c.end());

    if (c != b) {
      cout << "No" << endl;
      exit(0);
    }
  }

  // 3 x 3
  for (ll i = 0; i < N; i += 3) {
    for (ll j = 0; j < N; j += 3) {
      vector<ll> c;
      for (ll k = i; k < i + 3; ++k) {
        for (ll l = j; l < j + 3; ++l) {
          c.emplace_back(A[k][l]);
        }
      }
      sort(c.begin(), c.end());

      if (c != b) {
        cout << "No" << endl;
        exit(0);
      }
    }
  }

  cout << "Yes" << '\n';
}
