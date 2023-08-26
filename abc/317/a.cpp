#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;

int main() {
  ll N, H, X;
  cin >> N >> H >> X;

  vector<ll> P(N);
  for (auto& p : P) cin >> p;

  rep(i, N) {
    if (P[i] + H >= X) {
      cout << i + 1 << '\n';
      break;
    }
  }
}
