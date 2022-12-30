#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  string s;
  cin >> s;

  for (auto c : s) {
    if (c == '9') {
      cout << "Yes" << '\n';
      return 0;
    }
  }
  cout << "No" << '\n';
  return 0;
}