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
    ll s, t;
    cin >> s >> t;
    edge[s].emplace_back(t);
    ++indegree[t];
  }

  queue<ll> que;
  auto push = [&](ll i) {
    if (indegree[i] == 0) que.emplace(i);
  };
  rep(i, n) push(i);

  vector<ll> ans;
  while (not que.empty()) {
    ll v = que.front();
    que.pop();
    ans.emplace_back(v);
    for (auto to : edge[v]) {
      --indegree[to];
      push(to);
    }
  }

  for (auto v : ans) cout << v << ' ';
  cout << '\n';
  return 0;
}