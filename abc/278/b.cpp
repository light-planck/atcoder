#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


bool ok(ll h, ll m) {
  ll a = h/10; ll b = h%10;
  ll c = m/10; ll d = h%10;

  ll ac = 10*a + c;
  ll bd = 10*b + d;

  return (0 <= ac and ac < 24) and (0 <= bd and bd < 60);
}


int main() {
  ll h, m;
  cin >> h >> m;

  while (not ok(h, m)) {
    ++m;

    if (m == 60) {
      ++h;
      m = 0;
    }
    if (h == 24) h = 0;
  }

  cout << h << " " << m << '\n';
  return 0;
}