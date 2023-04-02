#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n;
  cin >> n;

  string s;
  cin >> s;

  rep(i, n-1) {
    if (s[i] == s[i+1]) {
      cout << "No" << '\n';
      return 0;
    }
  }

  cout << "Yes" << '\n';
  return 0;
}