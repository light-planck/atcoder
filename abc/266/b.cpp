#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n;
  cin >> n;

  ll m = 998244353;
  while (n < 0) {
    n += m;
  }
  cout << n % m << '\n';
  return 0;
}