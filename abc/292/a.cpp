#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  string s;
  cin >> s;

  for (auto c : s) {
    cout << (char)toupper(c);
  }
  cout << '\n';
  return 0;
}