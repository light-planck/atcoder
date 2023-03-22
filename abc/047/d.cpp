#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n, t;
  cin >> n >> t;

  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  constexpr ll inf = 1ll << 60;
  ll min_a = inf;
  ll val = 0;
  ll cnt = 0;
  rep(i, n) {
    if (a[i]-min_a > 0) {
      if (a[i]-min_a == val) ++cnt;
      else if (a[i]-min_a > val) {
        val = a[i]-min_a;
        cnt = 1;
      }
    }
    else min_a = a[i];
  }

  cout << cnt << '\n';
  return 0;
}