#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll x, t;
  cin >> x >> t;

  cout << max(x-t, 0ll) << '\n';
  return 0;
}