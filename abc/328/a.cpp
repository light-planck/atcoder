#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;

int main() {
  ll N, X;
  cin >> N >> X;

  ll ans = 0;
  rep(i, N) {
    ll s;
    cin >> s;
    if (s <= X) ans += s;
  }

  cout << ans << '\n';
}
