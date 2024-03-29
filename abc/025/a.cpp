#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  string s;
  cin >> s;

  ll idx;
  cin >> idx;
  --idx;

  set<string> ans;
  ll n = s.size();
  for (ll i = 0; i < n; ++i) {
    for (ll j = i+1; j < n; ++j) {
      ans.emplace(string{s[i], s[i]});
      ans.emplace(string{s[j], s[j]});

      ans.emplace(string{s[i], s[j]});
      ans.emplace(string{s[j], s[i]});
    }
  }

  for (auto x : ans) {
    if (idx == 0) cout << x << '\n';
    --idx;
  }
  return 0;
}