#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;

int main() {
  ll N;
  cin >> N;

  vector<ll> A(3 * N);
  for (auto& a : A) cin >> a;

  vector idx(N, vector<ll>());
  rep(i, 3 * N) { idx[A[i] - 1].emplace_back(i); }

  vector<pair<ll, ll>> f;
  rep(i, N) f.emplace_back(idx[i][1], i);
  ranges::sort(f);

  for (auto [_, i] : f) {
    cout << i + 1 << '\n';
  }
  return 0;
}
