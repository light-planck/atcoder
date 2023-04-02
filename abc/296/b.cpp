#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n = 8;

  vector<string> s(n);
  rep(i, n) cin >> s[i];
  reverse(s.begin(), s.end());

  rep(i, n) rep(j, n) {
    if (s[i][j] == '*') {
      cout << (char)('a'+j) << i+1 << endl;
    }
  }
  return 0;
}