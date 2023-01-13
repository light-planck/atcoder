#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  string s, t;
  cin >> s >> t;

  ll n = stoll(s+t);
  for (ll i = 2; i*i <= n; ++i) {
    if (i*i == n) {
      cout << "Yes" << '\n';
      return 0;
    }
  }

  cout << "No" << '\n';
  return 0;
}