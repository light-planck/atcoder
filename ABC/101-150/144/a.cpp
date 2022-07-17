#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
const int inf = INT_MAX;
const int mod = 1000000007;

int main() {
  int a, b;
  cin >> a >> b;
  if (a > 9 or b > 9) cout << -1 << endl;
  else cout << a * b << endl;
  return 0;
}