#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll a, b;
  cin >> a >> b;

  ll ans = max({a+b, a-b, a*b});
  cout << ans << '\n';
  return 0;
}