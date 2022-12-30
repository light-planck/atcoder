#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll a, b, x;
  cin >> a >> b >> x;

  if (a <= x and x <= (a+b)) cout << "YES" << '\n';
  else cout << "NO" << '\n';
  return 0;
}