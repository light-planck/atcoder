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
  ll n, m;
  cin >> n >> m;

  vector<string> s(n);
  rep(i, n) cin >> s[i];
  sort(s.begin(), s.end());

  set<string> st;
  rep(i, m) {
    string t;
    cin >> t;
    st.emplace(t);
  }

  ll rem = 16 - (n-1);
  rep(i, n) rem -= s[i].size();

  auto dfs = [&](auto dfs, string x, ll idx, ll r) -> void {
    if (r < 0) return;

    if (idx == n) {
      if (3 <= x.size() and (not st.count(x))) {
        cout << x << '\n';
        exit(0);
      }
      return;
    }

    if (x.size() > 0 and x.back() != '_') {
      dfs(dfs, x+'_', idx, r);
    }
    else {
      dfs(dfs, x+s[idx], idx+1, r);
      if (x.size() > 0) dfs(dfs, x+'_', idx, r-1);
    }
  };

  do {
    dfs(dfs, "", 0, rem);
  } while (next_permutation(s.begin(), s.end()));

  cout << -1 << '\n';
  return 0;
}