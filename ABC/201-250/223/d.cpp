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

  ll n, m;
  cin >> n >> m;

  vector<vector<ll>> g(n);
  vector<ll> in_deg(n);
  rep(i, m) {
    ll a, b;
    cin >> a >> b;
    --a; --b;

    // a -> bだからbの入次数を1増やす
    ++in_deg[b];
    g[a].emplace_back(b);
  }

  priority_queue<ll, vector<ll>, greater<ll>> heap;
  rep(i, n) {
    if (in_deg[i] == 0) heap.push(i);
  }

  vector<ll> ans;
  while (heap.size()) {
    ll u = heap.top();
    heap.pop();
    ans.emplace_back(u);

    for (auto v : g[u]) {
      --in_deg[v];
      
      if (in_deg[v] == 0) {
        heap.push(v);
      }
    }
  }

  if (ans.size() == n) {
    for (auto v : ans) {
      cout << v + 1 << "\n";
    }
  }
  else {
    cout << -1 << "\n";
  }
  return 0;
}