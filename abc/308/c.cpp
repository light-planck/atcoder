#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;

int main() {
  ll N;
  cin >> N;

  vector<long double> A(N), B(N);
  rep(i, N) {
    long double a, b;
    cin >> a >> b;
    A[i] = a;
    B[i] = b;
  }

  vector<pair<long double, ll>> success;
  rep(i, N) { success.emplace_back(A[i] / (A[i] + B[i]), -i); }
  ranges::sort(success, ranges::greater());

  for (auto [_, i] : success) {
    cout << -i + 1 << '\n';
  }
  return 0;
}
