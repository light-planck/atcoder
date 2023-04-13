#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll a, b;
  cin >> a >> b;

  ll ans = 0;
  while (a != b) {
    // a <= bにする
    if (a > b) swap(a, b);

    if (b%a == 0) {
      ans += b/a - 1;
      break;
    }

    ans += b / a;
    b -= (b/a) * a;
  }

  cout << ans << '\n';
  return 0;
}