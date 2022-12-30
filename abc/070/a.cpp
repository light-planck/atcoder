#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  string s;
  cin >> s;

  ll n = s.size();
  ll l = 0; ll r = n-1;
  while (l < r) {
    if (s[l] != s[r]) {
      cout << "No" << '\n';
      return 0;
    }
    ++l; --r;
  }
  cout << "Yes" << '\n';
  return 0;
}