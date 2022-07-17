#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
const int inf = INT_MAX;
const int mod = 1000000007;

int main() {
  ll a, b, k;
  cin >> a >> b >> k;
  if (k <= a) cout << a - k << " " << b << endl;
  else if (k <= a + b) cout << 0 << " " << b - (k - a) << endl;
  else cout << 0 << " " << 0 << endl;
  return 0;
}