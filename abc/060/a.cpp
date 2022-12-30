#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  string a, b, c;
  cin >> a >> b >> c;

  if (a.back() == b[0] and b.back() == c[0]) cout << "YES" << '\n';
  else cout << "NO" << '\n';
  return 0;
}