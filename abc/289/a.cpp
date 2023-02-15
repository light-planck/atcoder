#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  string s;
  cin >> s;

  for (auto c : s) {
    if (c == '0') cout << '1';
    else cout << '0';
  }
  cout << '\n';
  return 0;
}