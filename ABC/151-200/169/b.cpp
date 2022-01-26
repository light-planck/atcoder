#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
const int inf = INT_MAX;
const int mod = 1000000007;

int main() {
  int n; cin >> n;
  ll ans = 1;
  const ll mx = 1e18;
  rep(i, n) {
    ll a; cin >> a;
    if (a == 0) {
      cout << 0 << endl;
      return 0;
    }
    if (mx/ans < a) {
      cout << -1 << endl;
      return 0;
    }
    ans *= a;
  }
  cout << ans << endl;
  return 0;
}