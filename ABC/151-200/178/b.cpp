#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
const int inf = INT_MAX;
const int mod = 1000000007;

int main() {
  ll a, b, c, d;
  cin >> a >> b >> c >> d;
  ll ans = max({a * c, a * d, b * c, b * d});
  cout << ans << endl;
}