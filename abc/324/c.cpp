#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;

int main() {
  ll N;
  cin >> N;

  string T;
  cin >> T;

  ll m = T.size();

  vector<string> left(m + 1);
  left[0] = "";
  rep(i, m) left[i + 1] = left[i] + T[i];

  vector<string> right(m + 1);
  right[0] = "";
  rep(i, m) right[i + 1] = T[m - 1 - i] + right[i];

  unordered_set<string> deleted;
  unordered_set<string> add;
  unordered_set<string> changed;
  rep(i, m + 1) {
    if (i < m) deleted.emplace(left[i] + right[m - i - 1]);

    rep(j, 'z' - 'a' + 1) {
      char c = char('a' + j);

      add.emplace(left[i] + c + right[m - i]);
      if (i < m) changed.emplace(left[i] + c + right[m - i - 1]);
    }
  }

  vector<ll> ans;
  rep(i, N) {
    string s;
    cin >> s;

    if (s == T or add.contains(s) or deleted.contains(s) or
        changed.contains(s)) {
      ans.emplace_back(i + 1);
    }
  }

  cout << ans.size() << '\n';
  for (auto x : ans) cout << x << '\n';
}
