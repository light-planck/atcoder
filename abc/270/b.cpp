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
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll x, y, z;
  cin >> x >> y >> z;

  if (x < 0) {
    x *= -1;
    y *= -1;
    z *= -1;
  }

  if (y > x or y < 0) cout << x << '\n';
  else if (z < y) {
    if (z > 0) cout << x << '\n';
    else cout << -2*z + x << '\n';
  }
  else cout << -1 << '\n';
  return 0;
}