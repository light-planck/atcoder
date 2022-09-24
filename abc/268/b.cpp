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
  string s;
  cin >> s;

  string t;
  cin >> t;

  ll n = s.size();
  ll m = t.size();

  if (n > m) {
    cout << "No" << '\n';
    return 0;
  }

  rep(i, n) {
    if (s[i] != t[i]) {
      cout << "No" << '\n';
      return 0;
    }
  }

  cout << "Yes" << '\n';
  return 0;
}