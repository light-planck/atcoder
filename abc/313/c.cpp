#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;

int main() {
  ll N;
  cin >> N;

  vector<ll> A(N);
  for (auto& a : A) cin >> a;
  ranges::sort(A, ranges::greater());

  ll s = accumulate(A.begin(), A.end(), 0ll);
  vector<ll> b(N, s / N);
  rep(i, s % N) b[i] = s / N + 1;

  ll ans = 0;
  rep(i, N) ans += abs(A[i] - b[i]);
  cout << ans / 2 << '\n';
}
