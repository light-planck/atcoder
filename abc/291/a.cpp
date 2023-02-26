#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  string s;
  cin >> s;

  ll ans = 0;
  ll n = s.size();
  rep(i, n) {
    if (isupper(s[i])) ans = i + 1;
  }
  cout << ans << '\n';
  return 0;
}