#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;

int main() {
  ll N, X;
  cin >> N >> X;

  vector<ll> A(N - 1);
  for (auto& a : A) cin >> a;

  auto [min_a, max_a] = ranges::minmax_element(A);
  ll sum = accumulate(A.begin(), A.end(), 0ll);
  for (ll i = 0; i <= 100; ++i) {
    if (i < *min_a) {
      if (sum - *max_a >= X) {
        cout << i << '\n';
        exit(0);
      }
    } else if (i > *max_a) {
      if (sum - *min_a >= X) {
        cout << i << '\n';
        exit(0);
      }
    } else {
      if (sum - *min_a - *max_a + i >= X) {
        cout << i << '\n';
        exit(0);
      }
    }
  }

  cout << -1 << '\n';
}
