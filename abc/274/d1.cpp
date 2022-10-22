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
  ll n, x, y;
  cin >> n >> x >> y;

  ll a0;
  cin >> a0;
  x -= a0;

  vector<ll> dx, dy;
  rep(i, n-1) {
    ll a;
    cin >> a;
    if (i & 1) dx.emplace_back(a);
    else dy.emplace_back(a);
  }

  ll s = dx.size();
  ll t = dy.size();

  vector<ll> dpx(s+1);
  rep(i, s) {

  }
  return 0;
}