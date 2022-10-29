#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <deque>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
#include <complex>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;
using ldouble = long double;
using Point = complex<ldouble>;


// 外積
ldouble cross(const Point& a, const Point& b) {
  return a.real()*b.imag() - a.imag()*b.real();
}


// 内積
ldouble dot(const Point& a, const Point& b) {
  return a.real()*b.real() + a.imag()*b.imag();
}


int main() {
  ll n = 9;

  vector<string> s(n);
  rep(i, n) cin >> s[i];

  ll ans = 0;
  rep(i1, n) rep(j1, n) {
    if (s[i1][j1] == '.') continue;
    
    rep(i2, n) rep(j2, n) {
      if (i1 == i2 and j1 == j2) continue;
      if (s[i2][j2] == '.') continue;

      rep(i3, n) rep(j3, n) {
        if (i2 == i3 and j2 == j3) continue;
        if (i1 == i3 and j1 == j3) continue;
        if (s[i3][j3] == '.') continue;

        vector<Point> p(3);
        p[0] = Point(i1, j1);
        p[1] = Point(i2, j2);
        p[2] = Point(i3, j3);

        rep(i, 3) {
          Point a = p[(i+1)%3] - p[i];
          Point b = p[(i+2)%3] - p[i];
          if (dot(a, b) != 0) continue;
          if (cross(a, b) < 0) continue;
          if (abs(a) != abs(b)) continue;
          Point d = p[i] + a + b;
          ll i4 = d.real(); ll j4 = d.imag();

          if (i4 < 0 or i4 >= n) continue;
          if (j4 < 0 or j4 >= n) continue;

          if (s[i4][j4] == '#') ++ans;
        }
      }
    }
  }

  cout << ans/12 << '\n';
  return 0;
}