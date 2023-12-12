#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;

int main() {
  ll N, L;
  cin >> N >> L;

  vector<ll> A(N);
  for (auto& a : A) cin >> a;

  ll ans = 0;
  for (auto a : A) {
    if (a >= L) ++ans;
  }

  cout << ans << '\n';
}
