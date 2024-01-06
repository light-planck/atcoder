#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;

int main() {
  ll A, M, L, R;
  cin >> A >> M >> L >> R;

  L -= A;
  R -= A;

  ll ans = 0;
  if (A < L) {
    ans = abs(R) / M - abs(L - 1) / M;
  } else if (A > R) {
    ans = abs(L) / M + abs(R - 1) / M;
  } else {
    ans = abs(R) / M + abs(L) / M + 1;
  }

  cout << ans << '\n';
}
