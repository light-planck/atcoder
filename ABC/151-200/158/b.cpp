#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
const int inf = INT_MAX;
const int mod = 1000000007;

int main() {
  ll n, a, b;
  cin >> n >> a >> b;
  ll ans = 0;
  ll q = n / (a + b);
  ans = q * a;
  ll r = n % (a + b);
  ans += min(r, a);
  cout << ans << endl;
  return 0;
}