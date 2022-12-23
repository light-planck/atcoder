#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;
#include <atcoder/dsu>
using namespace atcoder;


int main() {
  ll n, m;
  cin >> n >> m;

  vector<pair<ll, ll>> edge;
  rep(_, m) {
    ll a, b;
    cin >> a >> b;
    --a; --b;
    edge.emplace_back(a, b);
  }
  reverse(edge.begin(), edge.end());

  dsu uf(n);
  vector<ll> ans(m);
  ans[0] = n * (n-1) / 2;

  rep(i, m-1) {
    auto [a, b] = edge[i];
    ans[i+1] = ans[i];

    if (uf.same(a, b)) continue;

    ans[i+1] -= uf.size(a) * uf.size(b);
    uf.merge(a, b);
  }

  reverse(ans.begin(), ans.end());
  for (auto num : ans) cout << num << '\n';
  return 0;
}