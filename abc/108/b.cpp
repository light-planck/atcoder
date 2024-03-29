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
  vector<Point> p(4);
  rep(i, 2) {
    ldouble x, y;
    cin >> x >> y;
    p[i] = Point(x, y);
  }

  Point v = p[1] - p[0];
  Point a = rotate(v, deg2rad(90.0));
  p[2] = p[1] + a;
  p[3] = p[0] + a;

  auto print = [](Point p) {
    // ll x = p.real() + 1e-1; ll y = p.imag() + 1e-1;
    // cout << x << " " << y << '\n';
    cout << p.real() << " " << p.imag() << '\n';
  };

  print(p[2]);
  print(p[3]);
  return 0;
}