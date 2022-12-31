#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


using ldouble = long double;
using Point = complex<ldouble>;
const ldouble EPS = 1e-7;
const ldouble PI = acos(-1);


// ラジアン・度変換
ldouble rad2deg(const ldouble& rad) { return rad * 180.0 / PI; }
ldouble deg2rad(const ldouble& deg) { return deg * PI / 180.0; }


// 点pを反時計回りにtheta回転
Point rotate(const Point& p, const ldouble& theta) {
  return Point( cos(theta)*p.real() - sin(theta)*p.imag(),
                sin(theta)*p.real() + cos(theta)*p.imag() );
}


int main() {
  Point p = {0, 1};
  cout << p.imag() << " " << p.real() << '\n';

  rotate(p, deg2rad(90));
  cout << p.imag() << " " << p.real() << '\n';
  return 0;
}