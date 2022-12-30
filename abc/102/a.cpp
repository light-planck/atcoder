#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n;
  cin >> n;

  if (n%2 == 1) cout << 2*n << '\n';
  else cout << n << '\n';
  return 0;
}