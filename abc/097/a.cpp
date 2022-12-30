#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll a, b, c, d;
  cin >> a >> b >> c >> d;

  if ((abs(a-b) <= d and abs(b-c) <= d) or (abs(a-c) <= d)) cout << "Yes" << '\n';
  else cout << "No" << '\n';
  return 0;
}