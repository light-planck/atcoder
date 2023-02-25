#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n, a, b, c, d;
  cin >> n >> a >> b >> c >> d;

  bool ok = true;
  if (b > n/2 or c > n/2) ok = false;
  if (abs(b-c) >= 2) ok = false;
  if (a*d > 0 and b == 0 and c == 0) ok = false;

  if (ok) cout << "Yes" << '\n';
  else cout << "No" << '\n';
  return 0;
}