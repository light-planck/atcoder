#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;
using ldouble = long double;


int main() {
  ll a, b;
  cin >> a >> b;

  auto f = [&](ll x) {
    return b*x + a/pow(x+1, 0.5);
  };

  auto df = [&](ll x) {
    return b - a/(2*pow(x+1, 3.0/2));
  };

  ll ng = -1;
  ll ok = 9e18;
  while (abs(ok-ng) > 1) {
    ll mid = min(ok, ng) + abs(ok-ng)/2;
  
    auto check = [&]() {
      return df(mid) >= 0;
    };
  
    if (check()) ok = mid;
    else ng = mid;
  }

  printf("%.10f\n", f(ok));
  return 0;
}