#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n = 13;
  vector<ll> a(n);
  rep(i, n) {
    if (i == 2) a[i] = 2;
    if (i == 4 or i == 6 or i == 9 or i == 11) a[i] = 1;
  }

  ll x, y;
  cin >> x >> y;
  
  if (a[x] == a[y]) cout << "Yes" << '\n';
  else cout << "No" << '\n';
  return 0;
}