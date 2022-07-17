#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
const int inf = INT_MAX;
const int mod = 1000000007;

int main() {
  string a, b;
  cin >> a >> b;
  int ans = max(a[0] - '0' + a[1] - '0' + a[2] - '0', b[0] - '0' + b[1] - '0' + b[2] - '0');
  cout << ans << endl;
}