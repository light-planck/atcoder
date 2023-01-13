#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll x, y;
  cin >> x >> y;

  ll ans = 1;
  while (x < y) {
    ++ans;
    x *= 2;
  }
  
  if (y != x) --ans;
  cout << ans << '\n';
  return 0;
}