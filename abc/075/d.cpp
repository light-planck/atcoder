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
#include <atcoder/modint>
using namespace atcoder;
using mint = modint1000000007;


int main() {
  ll n;
  cin >> n;

  vector<string> s(2);
  rep(i, 2) cin >> s[i];

  string t;
  ll j = 0;
  while (j < n) {

    // a: 縦1列
    if (s[0][j] == s[1][j]) {
      t += 'a';
      ++j;
    }

    // b: 横1列×2
    else {
      t += 'b';
      j += 2;
    }
  }

  mint ans = 0;
  if (t[0] == 'a') ans = 3;
  else ans = 6;

  ll m = t.size();
  for (ll i = 1; i < m; ++i) {
    if (t[i - 1] == 'a') {
      ans *= 2;
    }
    else {
      if (t[i] == 'b') ans *= 3;
    }
  }

  cout << ans.val() << '\n';
  return 0;
}