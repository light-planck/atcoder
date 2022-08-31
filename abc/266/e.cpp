#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <deque>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;
using ldouble = long double;


int main() {
  ll n;
  cin >> n;

  ll dice = 6;
  ldouble ans = 0;
  rep(i, n) {
    ldouble now = 0;
    for (ll d = 1; d <= dice; ++d) {
      now += max((ldouble)d, ans) / 6;
    }
    ans = now;
  }

  printf("%.10Lf\n", ans);
  return 0;
}