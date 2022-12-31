#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll a, b;
  cin >> a >> b;

  if (a%b == 0) cout << a%b << '\n';
  else cout << b - a%b << '\n';
  return 0;
}