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
  while (n > 0) {
    if (n & 1) {
      s += "1";
    }
    else s += "0";
    n >>= 1;
  }

  ll m = s.size();
  set<ll> st = {0};

  auto dfs = [&](auto dfs, ll i, string t) -> void {
    if (i == m) return;

    if (t != "") {
      ll res = 0;
      for (auto c : t) {
        res = res*2 + (c-'0');
      }
      st.emplace(res);
    }

    dfs(dfs, i+1, '0'+t);

    if (s[i] == '1') {
      dfs(dfs, i+1, '1'+t);
    }
  };
  dfs(dfs, 0, "");

  for (auto x : st) cout << x << '\n';
  return 0;
}