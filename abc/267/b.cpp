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

  if (s[0] == '1') {
    cout << "No" << '\n';
    return 0;
  }

  vector<bool> t(10);
  rep(i, 10) if (s[i] == '0') t[i] = true;

  vector<bool> down(7);
  down[0] = t[6];
  down[1] = t[3];
  down[2] = t[7] and t[1];
  down[3] = t[0] and t[4];
  down[4] = t[2] and t[8];
  down[5] = t[5];
  down[6] = t[9];

  for (ll i = 0; i < 7; ++i) {
    for (ll j = i+1; j < 7; ++j) {
      for (ll k = j+1; k < 7; ++k) {
        if (not down[i] and not down[k] and down[j]) {
          cout << "Yes" << '\n';
          return 0;
        }
      }
    }
  }

  cout << "No" << '\n';
  return 0;
}