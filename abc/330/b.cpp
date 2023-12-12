#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;

int main() {
  ll N, L, R;
  cin >> N >> L >> R;

  vector<ll> A(N);
  for (auto& a : A) cin >> a;

  for (auto a : A) {
    if (a <= L) cout << L << '\n';
    else if (L < a && a < R) cout << a << '\n';
    else cout << R << '\n';
  }
}
