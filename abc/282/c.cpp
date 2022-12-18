#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n;
  cin >> n;

  string s;
  cin >> s;

  bool can_erase = true;
  rep(i, n) {
    if (s[i] == '"') {
      can_erase ^= 1;
    }
    
    if (s[i] == ',') {
      if (can_erase) s[i] = '.';
    }
  }

  cout << s << '\n';
  return 0;
}