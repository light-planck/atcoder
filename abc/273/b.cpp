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
  ll x, k;
  cin >> x >> k;

  ll mod = 10;
  ll five = 5;
  rep(i, k) {
    ll d = x % mod;

    if (d >= five) x += mod;
    x -= d;

    mod *= 10;
    five *= 10;
    // cout << x << '\n';
  }

  cout << x << '\n';
  return 0;
}