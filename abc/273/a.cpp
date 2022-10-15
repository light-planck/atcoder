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


auto f (ll x) {
  if (x == 0) return 1LL;
    return x * f(x-1);
}

int main() {
  ll n;
  cin >> n;

  cout << f(n) << '\n';
  return 0;
}