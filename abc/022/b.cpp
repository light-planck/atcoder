#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n;
  cin >> n;

  set<ll> st;
  ll ans = 0;
  rep(i, n) {
    ll a;
    cin >> a;
    if (st.count(a)) ++ans;
    else st.emplace(a);
  }

  cout << ans << '\n';
  return 0;
}