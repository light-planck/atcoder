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
  ll n, a, b;
  cin >> n >> a >> b;

  vector<ll> x(n);
  rep(i, n) cin >> x[i];

  ll ans = 0;
  rep(i, n-1) {
    ans += min((x[i+1]-x[i])*a, b);
  }

  cout << ans << '\n';
  return 0;
}