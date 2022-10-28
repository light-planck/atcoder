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

  string s;
  cin >> s;

  vector<ll> left(n+1);
  rep(i, n) {
    left[i + 1] = left[i];
    if (s[i] == 'W') ++left[i + 1];
  }

  vector<ll> right(n+1);
  rep(i, n) {
    right[i + 1] = right[i];
    if (s[n-1-i] == 'E') ++right[i + 1];
  }

  ll ans = 9e18;
  auto chmin = [](auto& a, auto b) { if (a > b) a = b; };
  rep(i, n) {
    ll now = left[i] + right[n-1-i];
    chmin(ans, now);
  }

  cout << ans << '\n';
  return 0;
}