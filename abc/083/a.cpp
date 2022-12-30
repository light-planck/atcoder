#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll a, b, c, d;
  cin >> a >> b >> c >> d;

  ll l = a + b; ll r = c + d;
  if (l > r) cout << "Left" << '\n';
  else if (l == r) cout << "Balanced" << '\n';
  else cout << "Right" << '\n';
  return 0;
}