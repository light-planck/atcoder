#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n;
  cin >> n;

  string s;
  cin >> s;

  for (ll i = 0; i < n; ++i) {
    for (ll j = i+1; j < n; ++j) {
      for (ll k =j+1; k < n; ++k) {
        if (s[i] == '|' and s[j] == '*' and s[k] == '|') {
          cout << "in" << '\n';
          return 0;
        }
      }
    }
  }

  cout << "out" << '\n';
  return 0;
}