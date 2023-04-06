#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n;
  cin >> n;

  vector a(n, 0ll);
  rep(i, n) cin >> a[i];

  ll ans = 0;
  ll sum = 0;
  ll r = 0;
  rep(l, n) {
    while ((r<n) and (sum+a[r]==(sum^a[r]))) {
      sum += a[r];
      ++r;
    }

    ans += r - l;

    // [l, l]が条件を満たさないとき、lだけインクリメントされるので
    // rもインクリメントする
    if (r == l) ++r;
    else sum -= a[l];
  }

  cout << ans << '\n';
  return 0;
}