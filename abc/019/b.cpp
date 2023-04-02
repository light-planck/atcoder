#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  string s;
  cin >> s;

  vector<pair<char, ll>> encoded;
  ll cnt = 0;
  char prev = '.';
  for (char c : s) {
    if (c == prev) ++cnt;
    else {
      if (prev != '.') {
        encoded.emplace_back(prev, cnt);
      }

      cnt = 1;
      prev = c;
    }
  }
  encoded.emplace_back(prev, cnt);

  string ans = "";
  for (auto [c, cnt] : encoded) {
    ans += c + to_string(cnt);
  }
  cout << ans << '\n';
  return 0;
}