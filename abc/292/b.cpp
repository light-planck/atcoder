#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  
  ll n, q;
  cin >> n >> q;

  vector<ll> penalty(n);
  while (q--) {
    ll t, x;
    cin >> t >> x;
    --x;
    if (t == 1) ++penalty[x];
    if (t == 2) penalty[x] += 2;
    if (t == 3) {
      if (penalty[x] >= 2) cout << "Yes" << '\n';
      else cout << "No" << '\n';
    }
  }
  return 0;
}