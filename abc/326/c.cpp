#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;

int main() {
  ll N, M;
  cin >> N >> M;

  vector<ll> A(N);
  for (auto& a : A) cin >> a;
  ranges::sort(A);

  ll ans = 0;
  rep(i, N) {
    ll idx = ranges::lower_bound(A, M + A[i]) - A.begin();
    ans = max(ans, idx - i);
  }

  cout << ans << '\n';
}
