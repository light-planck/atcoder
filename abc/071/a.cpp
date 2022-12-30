#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll x, a, b;
  cin >> x >> a >> b;

  if (abs(x-a) < abs(x-b)) cout << 'A' << '\n';
  else cout << 'B' << '\n';
  return 0;
}