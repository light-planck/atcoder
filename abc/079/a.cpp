#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  string s;
  cin >> s;

  ll n = s.size();
  char prev = '\0';
  ll cnt = 0;
  rep(i, n) {
    if (s[i] == prev) ++cnt;
    else {
      prev = s[i];
      cnt = 1;
    }

    if (cnt == 3) {
      cout << "Yes" << '\n';
      return 0;
    }
  }

  cout << "No" << '\n';
  return 0;
}