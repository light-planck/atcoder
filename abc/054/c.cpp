#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n, m;
  cin >> n >> m;

  vector edge(n, set<ll>());
  rep(_, m) {
    ll a, b;
    cin >> a >> b;
    --a; --b;
    edge[a].emplace(b);
    edge[b].emplace(a);
  }

  vector<ll> idx(n);
  iota(idx.begin(), idx.end(), 0);

  ll ans = 0;
  do {
    if (idx[0] != 0) continue;

    ll cur = 0;
    bool ok = true;
    while (true) {
      ll now = idx[cur];
      ll to = idx[cur+1];

      if (not edge[now].count(to)) {
        ok = false;
        break;
      }

      ++cur;
      if (cur == n-1) break;
    }

    if (ok) ++ans;
  } while (next_permutation(idx.begin(), idx.end()));

  cout << ans << '\n';
  return 0;
}