#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll a, b, c;
  cin >> a >> b >> c;

  if (a+b >= c) cout << "Yes" << '\n';
  else cout << "No" << '\n';
  return 0;
}