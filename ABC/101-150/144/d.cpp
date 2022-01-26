#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;

const double kPi = acos(-1);

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  double a, b, x;
  cin >> a >> b >> x;

  double theta;
  double s = x / a;

  // 水面がbと接するとき
  // tan t = h / a
  if (s > a * b / 2) {
    double h = 2 * (a * b - s) / a;
    theta = atan2(h, a);
  }

  // 水面が底面aと接するとき
  // s = w * b => w = s / b
  else {
    double w = 2 * s / b;
    theta = atan2(b, w);
  }

  double deg = 180 * theta / kPi;
  printf("%.10f\n", deg);
  return 0;
}