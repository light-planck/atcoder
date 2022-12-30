#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll a, b;
  cin >> a >> b;

  if (a > b) cout << a-1 << '\n';
  else cout << a << '\n';
  return 0;
}