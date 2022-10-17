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

  string ans = "";

  while (n) {
    if (n & 1) ans += '1';
    else ans += '0';
    n >>= 1;
  }
  reverse(ans.begin(), ans.end());
  
  ll m = 10 - ans.size();
  ans = string(m, '0') + ans;

  cout << ans << '\n';
  return 0;
}