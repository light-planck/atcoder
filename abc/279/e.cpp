#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n, m;
  cin >> n >> m;

  vector<ll> a(m);
  for (auto& ai : a) cin >> ai, --ai;

  vector<ll> pre(m);
  ll cur = 0;
  rep(i, m) {
    pre[i] = cur;
    if (a[i] == cur) ++cur;
    else if (a[i]+1 == cur) --cur;
  }

  vector<ll> ans(m);
  vector<ll> pos(n);
  iota(pos.begin(), pos.end(), 0);
  for (ll i = m-1; i >= 0; --i) {
    ans[i] = pos[pre[i]];
    swap(pos[a[i]], pos[a[i]+1]);
  }

  for (auto x : ans) cout << x+1 << '\n';
  return 0;
}