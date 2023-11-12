#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;

int main() {
  ll N, Q;
  cin >> N >> Q;

  string S;
  cin >> S;

  vector<ll> sum(N + 1);
  rep(i, N) {
    sum[i + 1] = sum[i];

    if (S[i] == S[i + 1]) ++sum[i + 1];
  }

  while (Q--) {
    ll l, r;
    cin >> l >> r;
    --l;
    --r;
    cout << sum[r] - sum[l] << '\n';
  }
}
