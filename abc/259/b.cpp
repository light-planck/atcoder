#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


using ldouble = long double;
using Point = complex<ldouble>;
const ldouble EPS = 1e-7;
const ldouble PI = acos(-1);


ldouble rad2deg(const ldouble& rad) { return rad * 180.0 / PI; }
ldouble deg2rad(const ldouble& deg) { return deg * PI / 180.0; }


// 点pを反時計回りにtheta回転
Point rotate(const Point& p, const ldouble& theta) {
  return Point( cos(theta)*p.real() - sin(theta)*p.imag(),
                sin(theta)*p.real() + cos(theta)*p.imag() );
}


int main() {
  ldouble a, b, d;
  cin >> a >> b >> d;

  d = deg2rad(d);

  Point p(a, b);
  p = rotate(p, d);

  printf("%.10Lf %.10Lf\n", p.real(), p.imag());
  return 0;
}