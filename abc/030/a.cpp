#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  double a, b, c, d;
  cin >> a >> b >> c >> d;

  if (b/a > d/c) cout << "TAKAHASHI" << '\n';
  else if (b/a == d/c) cout << "DRAW" << '\n';
  else cout << "AOKI" << '\n';
  return 0;
}