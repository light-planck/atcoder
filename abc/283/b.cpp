#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  
  ll n;
  cin >> n;

  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  ll q;
  cin >> q;

  while (q--) {
    ll t;
    cin >> t;

    if (t == 1) {
      ll k, x;
      cin >> k >> x;
      --k;
      a[k] = x;
    }
    else {
      ll k;
      cin >> k;
      --k;
      cout << a[k] << '\n';
    }
  }
  return 0;
}