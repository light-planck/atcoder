#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n, m;
  cin >> n >> m;

  vector<vector<ll>> edge(n);
  rep(i, m) {
    ll a, b;
    cin >> a >> b;
    --a; --b;
    edge[a].emplace_back(b);
    edge[b].emplace_back(a);
  }

  for (auto& v : edge) sort(v.begin(), v.end());
  rep(i, n) {
    cout << edge[i].size() << " ";
    for (auto v : edge[i]) cout << v+1 << " ";
    cout << '\n';
  }
  return 0;
}