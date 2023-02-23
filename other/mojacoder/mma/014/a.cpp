#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n = 4;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];
  sort(a.begin(), a.end());
  ll sum = accumulate(a.begin(), a.end(), 0ll);
  if (sum >= 240 or sum-a[0] >= 210) cout << "Yes" << '\n';
  else cout << "No" << '\n';
  return 0;
}