#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n = 8;

  vector<string> s(n);
  rep(i, n) cin >> s[i];

  rep(i, n) rep(j, n) {
    if (s[i][j] == '*') {
      cout << (char)('a'+j) << 1+7-i << endl;
    }
  }
  return 0;
}