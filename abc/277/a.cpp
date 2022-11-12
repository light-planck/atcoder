#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n, x;
  cin >> n >> x;

  vector<ll> p(n);
  rep(i, n) cin >> p[i];

  rep(i, n) {
    if (p[i] == x) {
      cout << i+1 << '\n';
    }
  }
  return 0;
}