#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  string a, b;
  cin >> a >> b;

  if (a.size() == b.size()) {
    if (a > b) cout << "GREATER" << '\n';
    else if (a < b) cout << "LESS" << '\n';
    else cout << "EQUAL" << '\n';
  }
  else {
    if (a.size() > b.size()) cout << "GREATER" << '\n';
    else if (a.size() < b.size()) cout << "LESS" << '\n';
    else cout << "EQUAL" << '\n';
  }
  return 0;
}