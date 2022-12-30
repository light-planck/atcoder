#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  string s;
  cin >> s;

  cout << s.substr(0, 5) << " " << s.substr(6, 7) << " " << s.substr(14) << '\n';
  return 0;
}