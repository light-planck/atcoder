#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;

int main() { 
  ll n;
  cin >> n;

  ll dx = abs((n/5)*5 - n);
  ll ans = (n/5) * 5;

  auto round = [](ll a, ll b) { return (a + b - 1) / b; };
  if (abs(round(n, 5)*5 - n) < dx) ans = round(n, 5) * 5;

  cout << ans << '\n';
  return 0;
}