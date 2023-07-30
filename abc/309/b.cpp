#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;

int main() {
  ll N;
  cin >> N;

  vector<string> A(N);
  rep(i, N) cin >> A[i];

  vector<pair<ll, ll>> ij;
  rep(j, N) ij.emplace_back(0, j);
  for (ll i = 1; i < N; ++i) ij.emplace_back(i, N - 1);
  for (ll j = N - 2; j >= 0; --j) ij.emplace_back(N - 1, j);
  for (ll i = N - 2; i >= 0; --i) ij.emplace_back(i, 0);

  auto B = A;
  ll m = ij.size();
  rep(k, m) {
    auto [i, j] = ij[k];
    if (k + 1 < m) {
      auto [ni, nj] = ij[k + 1];
      B[ni][nj] = A[i][j];
    }
  }

  for (auto b : B) {
    cout << b << '\n';
  }
}
