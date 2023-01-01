#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n, m, a, b;
  cin >> n >> m >> a >> b;

  vector<ll> x(n);
  rep(i, n) cin >> x[i];
  sort(x.begin(), x.end());

  vector<ll> y(m);
  rep(i, m) cin >> y[i];
  sort(y.begin(), y.end());

  for (ll c = a+1; c <= b; ++c) {
    if (x.back() < c and c <= y[0]) {
      cout << "No War" << '\n';
      return 0;
    }
  }
  cout << "War" << '\n';
  return 0;
}