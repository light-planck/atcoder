#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n, m, k;
  cin >> n >> m >> k;

  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  multiset<ll> left;
  multiset<ll> right;
  ll sum = 0;

  auto push = [&](ll x) {
    left.emplace(x);
    sum += x;
    if ((ll)left.size() <= k) return;

    ll mx = *left.rbegin();
    right.emplace(mx);
    left.erase(left.find(mx));
    sum -= mx;
  };

  auto erase = [&](ll x) {
    if (*left.rbegin() < x) right.erase(right.find(x));
    else {
      left.erase(left.find(x));
      sum -= x;

      ll mn = *right.begin();
      left.emplace(mn);
      right.erase(right.find(mn));
      sum += mn;
    }
  };

  for (ll i = 0; i < n; ++i) {
    push(a[i]);
    if (i-m >= 0) erase(a[i-m]);

    if (i >= m-1) cout << sum << '\n';
  }
  return 0;
}