#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n;
  cin >> n;

  ll ok = 1;
  ll ng = n;
  ll mid = 0;

  auto solve = [&]() {
    mid = (ok+ng) / 2;
    cout << "? " << mid << '\n';

    ll b;
    cin >> b;

    if (b == 0) ok = mid;
    else ng = mid;

    if (abs(ok-ng)==1) {
      cout << "! " << ok << '\n';
      exit(0);
    }
  };

  while (n--) {
    solve();
  }
  return 0;
}