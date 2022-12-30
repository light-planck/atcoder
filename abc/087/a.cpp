#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll x, a, b;
  cin >> x >> a >> b;

  x -= a;
  while (x >= b) x -= b;
  
  cout << x << '\n';
  return 0;
}