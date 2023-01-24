#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n;
  cin >> n;

  vector<ll> ans;
  auto dfs = [&](auto dfs, string s) -> void {
    if ((ll)s.size() == 6) {
      string t = string{s[0], s[0], s[1], s[2], s[3], s[3], s[4], s[5], s[4]};
      ans.emplace_back(stoll(t));
      return;
    }

    rep(d, 10) {
      if (s.empty() and d == 0) continue;
      dfs(dfs, s+char(d+'0'));
    }
  };
  dfs(dfs, "");

  sort(ans.begin(), ans.end());
  cout << ans[n-1] << '\n';
  return 0;
}