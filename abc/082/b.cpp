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
  sort(s.begin(), s.end());

  string t;
  cin >> t;
  sort(t.rbegin(), t.rend());

  if (s < t) cout << "Yes" << '\n';
  else cout << "No" << '\n';
  return 0;
}