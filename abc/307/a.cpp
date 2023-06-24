#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;

int main() { 
  ll n;
  cin >> n;

  rep(i, n) {
    ll sum = 0;
    rep(j, 7) {
      ll a;
      cin >> a;
      sum += a;
    }
    cout << sum << '\n';
  }
  return 0;
}
