#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n;
  cin >> n;

  vector<ll> indegree(n);
  rep(i, n) {
    ll a;
    cin >> a;
    --a;
    ++indegree[a];
  }

  queue<ll> que;
  rep(i, n) {
    if (indegree[i] == 0) que.emplace(i);
  }

  vector<ll> path;
  while (not que.empty()) {
    ll v = que.front();
    que.pop();
    path.emplace_back(v);
    --indegree[v];
    if (indegree[v] == 0) que.emplace(v);
  }

  cout << n-path.size() << '\n';
  return 0;
}