#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n, d;
  cin >> n >> d;

  vector<ll> t(n);
  rep(i, n) cin >> t[i];

  rep(i, n-1) {
    if (t[i+1]-t[i] <= d) {
      cout << t[i+1] << '\n';
      return 0;
    }
  }

  cout << -1 << '\n';
  return 0;
}