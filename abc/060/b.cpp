#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll a, b, c;
  cin >> a >> b >> c;

  rep(i, a+1) {
    ll sum = (i+1)*b + c;
    if (sum % a == 0) {
      cout << "YES" << '\n';
      return 0;
    }
  }

  cout << "NO" << '\n';
  return 0;
}