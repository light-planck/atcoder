#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(x) (x).begin(),(x).end()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  ll n, q;
  cin >> n >> q;

  vector<ll> x(n);
  rep(i, n) cin >> x[i];

  vector<vector<ll>> g(n);
  rep(i, n - 1) {
    ll a, b;
    cin >> a >> b;
    --a; --b;
    g[a].emplace_back(b);
    g[b].emplace_back(a);
  }

  // max_nums[i]: 頂点iの部分木のうち値が大きいもの
  const ll max_k = 20;
  vector<vector<ll>> max_nums(n);

  // dfs
  auto dfs = [&](auto dfs, ll u, ll p) -> void {
    max_nums[u].emplace_back(x[u]);

    for (auto v : g[u]) {
      if (v == p) continue;

      dfs(dfs, v, u);
      
      // 子の部分木の値を追加する
      for (auto num : max_nums[v]) {
        max_nums[u].emplace_back(num);
      }

      // ソートしてサイズを20にする
      sort(max_nums[u].rbegin(), max_nums[u].rend());
      max_nums[u].resize(max_k);
    }
  };
  
  dfs(dfs, 0, -1);

  // クエリ
  while (q--) {
    ll v, k;
    cin >> v >> k;
    --v;
    cout << max_nums[v][k - 1] << "\n";
  }
  return 0;
}