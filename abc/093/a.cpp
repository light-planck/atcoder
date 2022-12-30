#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  string s;
  cin >> s;
  sort(s.begin(), s.end());

  if (s == "abc") cout << "Yes" << '\n';
  else cout << "No" << '\n';
  return 0;
}