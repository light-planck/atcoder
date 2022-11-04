#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n;
  cin >> n;

  vector<vector<ll>> edge(n);
  rep(i, n) {
    ll a;
    cin >> a;
    --a;
    edge[i].emplace_back(a);
  }

  vector<ll> dist(n, -1);
  dist[0] = 0;

  deque<ll> que;
  que.emplace_back(0);
  while (not que.empty()) {
    ll v = que.front(); que.pop_front();

    for (auto to : edge[v]) {
      if (dist[to] != -1) continue;

      dist[to] = dist[v] + 1;
      que.emplace_back(to);
    }
  }

  cout << dist[1] << '\n';
  return 0;
}