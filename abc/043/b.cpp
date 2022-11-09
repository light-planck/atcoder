#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  string s;
  cin >> s;

  string ans = "";
  for (auto c : s) {
    if (c == 'B') {
      if (not ans.empty()) ans.pop_back();
    }
    else ans += c;
  }

  cout << ans << '\n';
  return 0;
}