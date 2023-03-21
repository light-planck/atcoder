#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  string s;
  cin >> s;

  ll p = s.size() / 2;
  for (auto c : s) {
    if (c == 'p') --p;
  }
  cout << p << '\n';
  return 0;
}