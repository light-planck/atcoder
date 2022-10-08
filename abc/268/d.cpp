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
  
  auto dfs = [&](auto dfs, ll idx, string x) -> void {
    ll len = x.size();
    if (idx == n) {
      if (3 <= len and len <= 16) {
        if (not st.count(x)) {
          cout << x << '\n';
          exit(0);
        }
      }
      return;
    }
    else {
      if (len > 16) return;
    }

    if (len > 0) {
      if (x.back() != '_') dfs(dfs, idx, x+'_');
      else {
        dfs(dfs, idx, x+'_');
        dfs(dfs, idx+1, x+s[idx]);
      }
    }
    else dfs(dfs, idx+1, x+s[idx]);
  };

  do {
    dfs(dfs, 0, "");
  } while (next_permutation(s.begin(), s.end()));

  cout << -1 << '\n';
  return 0;
}