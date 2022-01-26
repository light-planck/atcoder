#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;

const ll kMod = LLONG_MAX;
long long Pow(long long x, long long n) {
  long long res = 1;

  while (n > 0) {
    if (n & 1) (res *= x) %= kMod;
    (x *= x) %= kMod;
    n >>= 1;
  }

  return res;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  ll x;
  cin >> x;

  for (ll a = -200; a <= 200; ++a) {
    for (ll b = -200; b <= 200; ++b) {
      if (Pow(a, 5) - Pow(b, 5) == x) {
        cout << a << " " << b << "\n";
        return 0;
      }
    }
  }
  return 0;
}