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

  vector<ll> x(n);
  rep(i, n) cin >> x[i];

  auto y = x;
  sort(y.begin(), y.end());

  ll a = y[n/2 - 1]; ll b = y[n/2];

  rep(i, n) {
    ll med = 0;
    if (x[i] <= a) med = b;
    else if (x[i] >= b) med = a;
    cout << med << '\n';
  }
  return 0;
}