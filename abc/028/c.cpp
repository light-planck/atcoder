#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n = 5;
  
  vector a(n, 0ll);
  rep(i, n) cin >> a[i];

  vector<ll> tmp;
  for (ll i = 0; i < n; ++i) {
    for (ll j = i+1; j < n; ++j) {
      for (ll k = j+1; k < n; ++k) {
        tmp.emplace_back(a[i]+a[j]+a[k]);
      }
    }
  }

  set<ll> st = set(tmp.begin(), tmp.end());
  vector<ll> ans = vector(st.begin(), st.end());
  reverse(ans.begin(), ans.end());
  cout << ans[2] << '\n';
  return 0;
}