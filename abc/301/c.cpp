#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {
  string s;
  cin >> s;

  string t;
  cin >> t;

  map<char, ll> s_cnt;
  ll s_atmark = 0;
  ll t_atmark = 0;

  for (auto c : s) {
    if (c == '@') ++s_atmark;
    else ++s_cnt[c];
  }

  for (auto c : t) {
    if (c == '@') ++t_atmark;
    else --s_cnt[c];
  }

  set<char> atcoder = {'a', 't', 'c', 'o', 'd', 'e', 'r'};
  for (auto [c, cnt] : s_cnt) {
    // tにあってsにない文字
    if (cnt < 0 and atcoder.count(c)) {
      s_atmark += cnt;
      s_cnt[c] = 0;
    }

    // sにあってtにない文字
    if (cnt > 0 and atcoder.count(c)) {
      t_atmark -= cnt;
      s_cnt[c] = 0;
    }
  }

  bool ok = (s_atmark >= 0 and t_atmark >= 0) and (s_atmark == t_atmark);
  if (ok) cout << "Yes" << '\n';
  else cout << "No" << '\n';
  return 0;
}