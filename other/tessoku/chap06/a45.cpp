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
  ll n; char x;
  cin >> n >> x;

  string s;
  cin >> s;

  ll point = 0;
  for (auto c : s) {
    if (c == 'R') point += 1;
    if (c == 'B') point += 2;
    if (c == 'W') point += 3;
  }

  if (x == 'R' and point%3 == 1) cout << "Yes" << '\n';
  else if (x == 'B' and point%3 == 2) cout << "Yes" << '\n';
  else if (x == 'W' and point%3 == 0) cout << "Yes" << '\n';
  else cout << "No" << '\n';
  return 0;
}