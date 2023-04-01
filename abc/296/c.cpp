#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n, x;
  cin >> n >> x;

  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  map<ll, ll> cnt;
  rep(i, n) ++cnt[a[i]];

  rep(i, n) {
    if (cnt.count(a[i]-x)) {
      cout << "Yes" << '\n';
      return 0;
    }
  }

  cout << "No" << '\n';
  return 0;
}