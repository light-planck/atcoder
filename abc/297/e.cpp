#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n, k;
  cin >> n >> k;

  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  auto push = [&](set<ll>& st, ll x) {
    st.emplace(x);
    while ((ll)st.size() > k+1) {
      ll mx = *st.rbegin();
      st.erase(mx);
    }
  };

  set<ll> dp;
  push(dp, 0);

  rep(i, n) {
    set<ll> prev;
    swap(prev, dp);

    for (ll x : prev) {
      rep(j, k) {
        if ((ll)dp.size() > k+1 and *dp.rbegin() < x+a[i]*j) break;
        push(dp, x+a[i]*j);
      }
    }
  }

  auto itr = dp.rbegin();
  cout << *itr << '\n';
  return 0;
}