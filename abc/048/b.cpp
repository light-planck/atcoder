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
  ll a, b, x;
  cin >> a >> b >> x;

  auto f = [&](ll t) {
    if (t == -1) return 0LL;
    return t/x + 1;
  };

  ll ans = f(b) - f(a-1);
  cout << ans << '\n';
  return 0;
}