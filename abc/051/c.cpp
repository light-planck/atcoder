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
  vector<ll> s(2), t(2);
  rep(i, 2) cin >> s[i];
  rep(i, 2) cin >> t[i];

  string ans = "";
  ll dx = t[0] - s[0];
  ll dy = t[1] - s[1];

  // 1
  rep(i, dy) ans += 'U';
  rep(i, dx) ans += 'R';

  // 2
  rep(i, dy) ans += 'D';
  rep(i, dx) ans += 'L';

  // 3
  ans += 'L';
  rep(i, dy+1) ans += 'U';
  rep(j, dx+1) ans += 'R';
  ans += 'D';

  // 4
  ans += 'R';
  rep(i, dy+1) ans += 'D';
  rep(j, dx+1) ans += 'L';
  ans += 'U';

  cout << ans << '\n';
  return 0;
}