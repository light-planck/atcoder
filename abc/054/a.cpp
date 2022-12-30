#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll a, b;
  cin >> a >> b;

  if (a == b) cout << "Draw" << '\n';
  else if (a == 1 or b == 1) {
    if (a == 1) cout << "Alice" << '\n';
    else cout << "Bob" << '\n';
  }
  else {
    if (a > b) cout << "Alice" << '\n';
    else cout << "Bob" << '\n';
  }
  return 0;
}