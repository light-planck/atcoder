#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;

// x * a < x + b
// をみたすときはa倍し、その後はbを足す

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  ll x, y, a, b;
  cin >> x >> y >> a >> b;

  ll ans = 0;
  while (true) {

    // x * a >= y
    if (x  >= y / a) break;

    // x * a >= x + b
    if (x >= x / a + b / a) break;

    x *= a;
    ans++;
  }

  ans += (y - 1 - x) / b;
  cout << ans << "\n";
  return 0;
}