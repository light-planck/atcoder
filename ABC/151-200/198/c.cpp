#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;
const int inf = 1e9;
const int mod = 1e9+7;

int main() {
  double r, x, y;
  cin >> r >> x >> y;
  double d = sqrt(x * x + y * y);
  if (d >= r) cout << ceil(d / r) << endl;
  else cout << 2 << endl;
  return 0;
}