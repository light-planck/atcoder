#include <iostream>
#include <vector>
#include <utility>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;
#include <atcoder/dsu>
using namespace atcoder;


int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  ll n, m, e;
  cin >> n >> m >> e;

  vector<pair<ll, ll>> edge(e);
  rep(i, e) {
    ll u, v;
    cin >> u >> v;
    --u; --v;
    edge[i] = {min(u, n), min(v, n)};
  }

  ll q;
  cin >> q;

  vector<ll> x(q);
  vector<bool> inital_edge(e, true);
  rep(i, q) {
    cin >> x[i];
    --x[i];
    inital_edge[x[i]] = false;
  }

  dsu uf(n + 1);

  // xに含まれない辺をあらかじめ張っておく
  for (ll i = 0; i < e; ++i) {
    if (not inital_edge[i]) continue;

    auto [u, v] = edge[i];
    uf.merge(u, v);
  }

  // クエリを逆から辺xを張っていく
  reverse(x.begin(), x.end());
  vector<ll> ans;
  for (auto i : x) {
    ans.emplace_back(uf.size(uf.leader(n)) - 1);
    auto [u, v] = edge[i];
    uf.merge(u, v);
  }

  reverse(ans.begin(), ans.end());
  for (auto x : ans) cout << x << '\n';
  return 0;
}