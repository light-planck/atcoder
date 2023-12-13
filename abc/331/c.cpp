#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;

int main() {
  ll N;
  cin >> N;

  vector<ll> A(N);
  rep(i, N) cin >> A[i];

  auto b = A;
  ranges::sort(b);

  vector<ll> sum_b(N + 1);
  rep(i, N) sum_b[i + 1] = sum_b[i] + b[i];

  for (auto a : A) {
    ll idx = ranges::upper_bound(b, a) - b.begin();
    cout << sum_b[N] - sum_b[idx] << '\n';
  }
}
