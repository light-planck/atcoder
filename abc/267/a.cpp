#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <deque>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  string s;
  cin >> s;

  string days[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};
  ll n = 5;
  rep(i, n) {
    if (s == days[i]) {
      cout << n - i << '\n';
      return 0;
    }
  }
  return 0;
}