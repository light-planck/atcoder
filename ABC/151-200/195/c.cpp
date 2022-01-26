#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;
const int inf = 1e9;
const int mod = 1e9+7;

int main() {
  ll n;
  cin >> n;
  ll ans = 0;

  if (n >= 1000) ans += n - 999;
  if (n >= 1000000) ans += n - 999999;
  if (n >= 1000000000) ans += n - 999999999;
  if (n >= 1000000000000) ans += n - 999999999999;
  if (n >= 1000000000000000) ans += n - 999999999999999;

  cout << ans << endl;
  return 0;
}