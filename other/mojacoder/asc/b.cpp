#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  
  ll n, q;
  cin >> n >> q;

  while (q--) {
    ll type;
    cin >> type;

    if (type == 1) {
      ll x, y;
      cin >> x >> y;
      --n;
    }
    if (type == 2) {
      ll x;
      cin >> x;
      ++n;
    }
    if (type == 3) {
      cout << n << '\n';
    }
  }
  return 0;
}