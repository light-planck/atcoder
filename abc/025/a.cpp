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
      ans.emplace(string{s[i]} + string{s[i]});
      ans.emplace(string{s[j]} + string{s[j]});

      ans.emplace(string{s[i]} + string{s[j]});
      ans.emplace(string{s[j]} + string{s[i]});
    }
  }
  sort(ans.begin(), ans.end());

  for (auto x : ans) {
    cout << x << '\n';
  }

  // cout << ans[idx] << '\n';
  return 0;
}