#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;

const double kPi = acos(-1);

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  double n;
  cin >> n;

  double x, y;

  cin >> x >> y;
  complex<double> p0(x, y);

  cin >> x >> y;
  complex<double> pn2(x, y);

  double theta = 2 * kPi / n;

  complex<double> m = (p0 + pn2) / 2.0;
  complex<double> r(cos(theta), sin(theta));
  complex<double> p1 = (p0 - m) * r + m;
  printf("%.10f %.10f\n", p1.real(), p1.imag());
  return 0;
}