#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;

int main() {
  ll N;
  cin >> N;

  vector<ll> A(N);
  for (auto& a : A) cin >> a, --a;

  ll ans = 0;
  vector<ll> cnt(N), sum(N);
  rep(k, N) {
    ans += (k - 1) * cnt[A[k]] - sum[A[k]];
    ++cnt[A[k]];
    sum[A[k]] += k;
  }

  rep(i, N) ans -= cnt[i] * (cnt[i] - 1) * (cnt[i] - 2) / 6;

  cout << ans << '\n';
}
