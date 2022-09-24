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

  ll ans = 0;
  ll now = 0;
  ll dx = 1;
  if (x < 0) dx = -1;
  bool can_break = false;

  while (now != x) {
    if (now == z) can_break = true;
    if (now == y and not can_break) {
      if (x > 0 and z < 0) ans += -2*z;
      else if (x < 0 and z > 0) ans += 2*z;
      else {
        cout << -1 << '\n';
        return 0;
      }
    }

    ++ans;
    now += dx;
  }

  cout << ans << '\n';
  return 0;
}