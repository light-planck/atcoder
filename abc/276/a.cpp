#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  string s;
  cin >> s;

  ll n = s.size();
  ll ans = -1;

  rep(i, n) {
    if (s[i] == 'a') ans = i + 1;
  }

  cout << ans << '\n';
  return 0;
}