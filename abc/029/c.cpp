#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n;
  cin >> n;

  vector<string> ans;

  auto dfs = [&](auto self, string s) -> void {
    if ((ll)s.size() == n) {
      ans.emplace_back(s);
      return;
    }

    rep(i, 3) {
      char c = 'a' + i;
      self(self, s+c);
    }
  };
  dfs(dfs, "");

  sort(ans.begin(), ans.end());
  for (auto x : ans) cout << x << '\n';
  return 0;
}