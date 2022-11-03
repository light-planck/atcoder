#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n;
  cin >> n;

  ll four = 0;
  ll two = 0;
  ll odd = 0;

  rep(i, n) {
    ll a;
    cin >> a;

    if (a%4 == 0) ++four;
    else if (a%2 == 0) ++two;
    else ++odd;
  }
  if (n%2 != 0) {
    if (four > 0) ++four;
    else if (two > 0) ++two;
  }
  two %= 2;

  bool ok = false;
  if (two%2 != 0) {
    if (four == two+odd) ok = true;
  }
  else {
    if ((four == odd) or (odd == 0)) ok = true;
  }

  if (ok) cout << "Yes" << '\n';
  else cout << "No" << '\n';
  return 0;
}