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

  ll k;
  cin >> k;

  ll n = s.size();

  rep(i, n) {
    char c = s[i];
    if (c == '1') {
      if (i == k-1) {
        cout << c << '\n';
        break;
      }
    }
    else {
      cout << c << '\n';
      break;
    }
  }
  return 0;
}