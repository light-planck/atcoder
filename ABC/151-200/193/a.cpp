#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
const int mod = 1000000007;

int main() {
  int a, b;
  cin >> a >> b;
  double ans = (double)100 * (a - b) / a;
  cout << ans << endl;
}