#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n;
  cin >> n;

  ll ans = 0;
  rep(i, n) {
    ll a;
    cin >> a;
    while (a%2 == 0) {
      a /= 2;
      ++ans;
    }
  }

  cout << ans << '\n';
  return 0;
}