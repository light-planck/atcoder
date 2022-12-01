#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  string s;
  cin >> s;

  string t;
  cin >> t;

  ll n = s.size();
  ll m = t.size();

  if (n < m) {
    cout << "No" << '\n';
    return 0;
  }

  rep(i, n) {
    if (i+m > n) break;

    if (s.substr(i, m) == t) {
      cout << "Yes" << '\n';
      return 0;
    }
  }

  cout << "No" << '\n';
  return 0;
}