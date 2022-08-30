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

  string t;
  cin >> t;

  ll n = s.size();
  ll m = t.size();

  // ?はaで埋めたい
  // マッチするような連続部分列が複数ありそうなら、
  // 最後の連続部分列を置換する
  ll left = -1;
  rep(i, n) {
    if (s[i] == '?' or s[i] == t[0]) {
      if (i + m - 1 >= n) continue;

      bool ok = true;
      rep(j, m) {
        if (s[i + j] != '?' and s[i + j] != t[j]) ok = false;
      }
      
      if (ok) left = i;
    }
  }

  if (left == -1) {
    cout << "UNRESTORABLE" << '\n';
    return 0;
  }

  for (ll i = left; i < left+m; ++i) {
    s[i] = t[i - left];
  }
  rep(i, n) {
    if (s[i] == '?') s[i] = 'a';
  }
  cout << s << '\n';
  return 0;
}