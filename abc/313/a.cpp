#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;

int main() {
  ll N;
  cin >> N;

  vector<ll> P(N);
  rep(i, N) cin >> P[i];

  ll max_p = 0;
  for (ll i = 1; i < N; ++i) {
    if (P[i] > max_p) max_p = P[i];
  }

  if (P.front() <= max_p)
    cout << max_p - P.front() + 1 << '\n';
  else
    cout << 0 << '\n';
}
