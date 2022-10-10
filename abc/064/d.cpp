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

  string s;
  cin >> s;

  ll cnt = 0;
  ll left = 0; ll right = 0;
  rep(i, n) {
    if (s[i] == '(') ++cnt;
    else {
      if (cnt == 0) ++left;
      else --cnt;
    }
  }
  right = cnt;

  string ans = "";
  rep(i, left) ans += "(";
  ans += s;
  rep(i, right) ans += ")";

  cout << ans << '\n';
  return 0;
}