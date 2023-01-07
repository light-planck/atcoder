#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  ll t;
  cin >> t;

  while (t--) {
    ll n;
    cin >> n;

    ll ans = 0;
    rep(i, n) {
      ll a;
      cin >> a;
      if (a%2 == 1) ++ans;
    }

    cout << ans << '\n';
  }
  return 0;
}