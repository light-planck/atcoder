#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  string s;
  cin >> s;

  ll n = s.size();
  ll left = 0; ll right = n-1;
  rep(i, n) {
    if (s[i] == 'A') {
      left = i;
      break;
    }
  }
  rep(i, n) {
    if (s[n-1-i] == 'Z') {
      right = n-1-i;
      break;
    }
  }

  cout << right-left+1 << '\n';
  return 0;
}