#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll m;
  cin >> m;

  ll vv = 0;
  if (m < 0.1) vv = 0;
  else if (m <= 5*1000) vv = 10 * m / 1000;
  else if (m <= 30*1000) vv = m/1000 + 50;
  else if (m <= 70*1000) {
    m /= 1000;
    m -= 30;
    m /= 5;
    m += 80;
    vv = m;
  }
  else vv = 89;

  if (vv < 10) cout << '0';
  cout << (ll)vv << '\n';
  return 0;
}