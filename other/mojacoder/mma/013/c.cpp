#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;
#include <atcoder/segtree>
using namespace atcoder;


ll op(ll a, ll b) { return min(a, b); }
ll e() { return 0; }


int main() {
  ll n, k;
  cin >> n >> k;

  vector<ll> a(n);
  rep(i, n) cin >> a[i];
  reverse(a.begin(), a.end());

  map<ll, vector<ll>> get_idx;
  rep(i, n) get_idx[a[i]].emplace_back(i);

  segtree<ll, op, e> seg(a);
  ll ans = 0;

  ll i = 1;
  while (i < n) {
    ll min_a = seg.prod(i, i+k);
    ans += min_a;

    vector<ll> idxs = get_idx[min_a];
    auto itr = lower_bound(idxs.begin(), idxs.end(), i);
    while (itr != idxs.end() and *itr < i+k) ++itr;
    i = *itr;
  }

  cout << ans << '\n';
  return 0;
}