#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll a, b, c, d;
  cin >> a >> b >> c >> d;

  cout << min(a, b) + min(c, d) << '\n';
  return 0;
}