#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
const int inf = INT_MAX;
const int mod = 1000000007;

int main() {
  int n;
  cin >> n;
  ll ans = 0;
  for (int i = 1; i <= n; i++){
    if (i % 3 != 0 and i % 5 != 0) ans += i;
  }
  cout << ans << endl;
  return 0;
}