#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll x, k;
  cin >> x >> k;

  ll ten = 1;
  rep(i, k) {
    ll d = (x/ten) % 10;

    x -= d * ten;
    if (d >= 5) x += ten*10;
    
    ten *= 10;
  }

  cout << x << '\n';
  return 0;
}