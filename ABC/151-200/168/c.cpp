#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;
const int inf = 1e9;
const int mod = 1e9+7;

int main() {
  double a, b;
  cin >> a >> b;
  int h, m;
  cin >> h >> m;

  // 角度
  double dega, degb;
  dega = (h * 60 + m) * 0.5;
  degb = (h * 60 + m) * 6;

  // 角度の差 [rad]
  double theta = abs(dega - degb);
  theta *= M_PI / 180;

  double d = sqrt(a * a + b * b - 2 * a * b * cos(theta));
  printf("%.10f\n", d);
  return 0;
}