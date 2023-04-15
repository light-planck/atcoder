#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  auto Pow = [](ll x, ll n) { ll res = 1; while (n > 0) { if (n & 1) res *= x; x *= x; n >>= 1; } return res; };
  cout << Pow(10, -2) << '\n';
  return 0;
}