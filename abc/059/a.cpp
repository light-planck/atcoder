#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n = 3;
  vector<string> s(n);
  rep(i, n) cin >> s[i];

  string ans = "";
  rep(i, n) ans += s[i][0];
  rep(i, n) ans[i] = toupper(ans[i]);
  
  cout << ans << '\n';
  return 0;
}