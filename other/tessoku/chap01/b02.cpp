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
  ll a, b;
  cin >> a >> b;

  for (ll i = a; i <= b; ++i) {
    if (100 % i == 0) {
      cout << "Yes" << '\n';
      return 0;
    }
  }

  cout << "No" << '\n';
  return 0;
}