#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;

int main() {
  ll N;
  cin >> N;

  vector edge(N, vector<ll>());
  rep(i, N) {
    ll a;
    cin >> a;
    --a;
    edge[i].emplace_back(a);
  }

  vector<ll> idx(N);
  vector<ll> path;

  ll v = 0;
  while (true) {
    if (idx[v] == 0) {
      idx[v] = ssize(path);
      path.emplace_back(v);
      v = edge[v][0];
      continue;
    }

    cout << ssize(path) - idx[v] << '\n';
    for (int i = idx[v]; i < ssize(path); ++i) {
      cout << path[i] + 1 << ' ';
    }
    cout << '\n';
    break;
  }
}
