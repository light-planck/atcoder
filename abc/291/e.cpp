#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n, m;
  cin >> n >> m;

  vector edge(n, vector<ll>());
  vector<ll> indegree(n);
  rep(i, m) {
    ll x, y;
    cin >> x >> y;
    --x; --y;
    edge[x].emplace_back(y);
    ++indegree[y];
  }

  queue<ll> que;
  auto push = [&](ll v) {
    if (indegree[v] == 0) que.emplace(v);
  };
  rep(i, n) push(i);

  vector<ll> idx;
  while (not que.empty()) {
    if ((ll)que.size() != 1) {
      cout << "No" << '\n';
      return 0;
    }

    ll v = que.front();
    que.pop();
    idx.emplace_back(v);

    for (auto to : edge[v]) {
      --indegree[to];
      push(to);
    }
  }

  vector<ll> ans(n);
  for (auto i : idx) ans[idx[i]] = i + 1;
  
  cout << "Yes" << '\n';
  for (auto v : ans) cout << v << ' ';
  cout << '\n';
  return 0;
}