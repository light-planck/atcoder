#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  char x, y;
  cin >> x >> y;

  if (x > y) cout << '>' << '\n';
  else if (x == y) cout << '=' << '\n';
  else cout << '<' << '\n';
  return 0;
}