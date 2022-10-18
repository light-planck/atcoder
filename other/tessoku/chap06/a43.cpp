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
  ll n, l;
  cin >> n >> l;

  ll ans = 0;
  rep(i, n) {
    ll a; char b;
    cin >> a >> b;
    auto chmax = [](auto& a, auto b) { if (a < b) a = b; };
    if (b == 'E') chmax(ans, l-a);
    else chmax(ans, a);
  }

  cout << ans << '\n';
  return 0;
}