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
  ll n;
  cin >> n;

  string ans;
  while (n) {
    ll d = n % 16;

    if (d >= 10) ans += 'A' + d-10;
    else ans += d + '0';
    n /= 16;
  }

  reverse(ans.begin(), ans.end());
  ll pad = 2 - ans.size();
  rep(i, pad) ans = '0' + ans;
  cout << ans << '\n';
  return 0;
}