#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n, p, q, r;
  cin >> n >> p >> q >> r;

  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  vector<ll> s(n + 1);
  rep(i, n) s[i + 1] = s[i] + a[i];

  set<ll> st;
  rep(i, n+1) st.emplace(s[i]);

  rep(i, n) {
    bool ok = true;

    ll sum = s[i] + p;
    if (not st.count(sum)) ok = false;
    sum += q;
    if (not st.count(sum)) ok = false;
    sum += r;
    if (not st.count(sum)) ok = false;

    if (ok) {
      cout << "Yes" << '\n';
      return 0;
    }
  }

  cout << "No" << '\n';
  return 0;
}