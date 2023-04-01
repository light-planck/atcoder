#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n;
  cin >> n;

  string s;
  cin >> s;

  char prev = 'x';
  rep(i, n) {
    if (s[i] == prev) {
      cout << "No" << '\n';
      return 0;
    }
    prev = s[i];
  }

  cout << "Yes" << '\n';
  return 0;
}