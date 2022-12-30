#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  vector<string> s(3);
  rep(i, 3) cin >> s[i];

  string ans = "";
  rep(i, 3) ans += s[i][i];

  cout << ans << '\n';
  return 0;
}