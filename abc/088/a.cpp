#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n;
  cin >> n;

  ll a;
  cin >> a;

  while (n >= 500) {
    n -= 500;
  }

  if (n <= a) cout << "Yes" << '\n';
  else cout << "No" << '\n';
  return 0;
}