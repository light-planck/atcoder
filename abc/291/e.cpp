#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n, m;
  cin >> n >> m;

  vector edge(n, vector<ll>());
  set<pair<ll, ll>> xy;
  vector<ll> in(n), out(n);
  rep(i, m) {
    ll x, y;
    cin >> x >> y;
    --x; --y;
    if (xy.count({x, y})) continue;
    edge[x].emplace_back(y);
    ++out[x];
    ++in[y];
    xy.emplace(x, y);
  }

  // (out, in) = (0, 1), (1, 0)
  // (out, in) = (1, 1)
  ll left = 0;
  ll right = 0;
  ll mid = 0;
  bool ok = true;
  rep(i, n) {
    if (out[i] == 1 and in[i] == 1) ++mid;
    else if (out[i] == 1 and in[i] == 0) ++left;
    else if (out[i] == 0 and in[i] == 1) ++right;
    else ok = false;
  }
  if (!(left == 1 and right == 1 and mid == n-2)) ok = false;
  if (not ok) {
    cout << "No" << '\n';
    return 0;
  }

  auto dfs = [&edge](auto dfs, ll v, vector<bool>& used, vector<ll>& idx) -> void {
    used[v] = true;
    for (auto to : edge[v]) {
      if (used[to]) continue;
      dfs(dfs, to, used, idx);
    }
    idx.emplace_back(v);
  };

  vector<ll> idx;
  vector<bool> used(n);
  rep(v, n) {
    if (used[v]) continue;
    dfs(dfs, v, used, idx);
  }
  reverse(idx.begin(), idx.end());

  if ((ll)idx.size() != n) {
    cout << "No" << '\n';
    return 0;
  }

  vector<ll> ans(n);
  rep(i, n) ans[idx[i]] = i + 1;

  cout << "Yes" << '\n';
  for (auto v : ans) cout << v << ' ';
  cout << '\n';
  return 0;
}