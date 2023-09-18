#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;

int main() {
  ll A, B;
  cin >> A >> B;

  ll ans = pow(A, B) + pow(B, A);
  cout << ans << '\n';
}
