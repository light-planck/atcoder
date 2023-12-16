#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;

int main() {
  ll N;
  cin >> N;

  constexpr ll HOUR = 24;
  vector<ll> W(N), X(N);
  rep(i, N) cin >> W[i] >> X[i];

  ll ans = 0;
  for (ll i = 0; i < HOUR; ++i) {
    ll sum = 0;
    rep(j, N) {
      ll h = (i + X[j]) % HOUR;
      if (9 <= h and h < 18) sum += W[j];
    }

    ans = max(ans, sum);
  }

  cout << ans << '\n';
}
