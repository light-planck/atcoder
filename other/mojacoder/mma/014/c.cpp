#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n;
  cin >> n;

  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  vector<ll> even, odd;
  rep(i, n) {
    if (i%2 == 0) even.emplace_back(a[i]);
    else odd.emplace_back(a[i]);
  }

  vector<ll> e = even;
  vector<ll> o = odd;
  sort(e.begin(), e.end());
  sort(o.begin(), o.end());
  vector<ll> b = a;
  sort(b.begin(), b.end());
  bool ok = true;
  rep(i, n) {
    if (i%2 == 0) {
      if (b[i] != e[i/2]) ok = false;
    }
    else {
      if (b[i] != o[i/2]) ok = false;
    }
  }
  if (not ok) {
    cout << -1 << '\n';
    exit(0);
  }

  ll ans = 0;
  rep(i, n) {
    if (i%2 == 0) {
      if (b[i] != even[i/2]) ++ans;
    }
    else if (b[i] != odd[i/2]) ++ans;
  }

  cout << ans/2 << '\n';
  return 0;
}