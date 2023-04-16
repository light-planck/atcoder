#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n, k;
  cin >> n >> k;

  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  set<ll> st = {0};

  auto push = [&](ll x) {
    rep(i, n) st.emplace(x + a[i]);
    while ((ll)st.size() > k+1) {
      st.erase(*st.rbegin());
    }
  };

  rep(i, k) {
    ll mn = *st.begin();
    push(mn);
    st.erase(mn);
  }

  cout << *st.begin() << '\n';
  return 0;
}