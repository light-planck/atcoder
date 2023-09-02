#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;

int main() {
  // fの大きいものからd個選びその総和がpより大きければパスを使う
  ll N, D, P;
  cin >> N >> D >> P;

  vector<ll> F(N);
  for (auto& f : F) cin >> f;

  sort(F.rbegin(), F.rend());

  ll ans = 0;
  ll sum = 0;
  ll l = 0;
  rep(i, N) {
    sum += F[i];
    if (i - l + 1 == D) {
      if (sum > P) {
        ans += P;
      } else {
        ans += sum;
      }
      sum = 0;
      l = i + 1;
    }
  }

  if (sum > P)
    ans += P;
  else
    ans += sum;

  cout << ans << '\n';
}
