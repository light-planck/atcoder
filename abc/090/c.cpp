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
  ll n, m;
  cin >> n >> m;

  if (n > m) swap(n, m);
  ll ans = 0;

  if (n == 1) {
    if (m == 1) ans = 1;
    else ans = m - 2;
  }
  else ans = (n-2) * (m-2);

  cout << ans << '\n';
  return 0;
}