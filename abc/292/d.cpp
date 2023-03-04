#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;
#include <atcoder/dsu>
using namespace atcoder;


int main() {
  ll n, m;
  cin >> n >> m;

  dsu uf(n);
  vector<ll> cnt(n);
  rep(i, m) {
    ll u, v;
    cin >> u >> v;
    --u; --v;
    uf.merge(u, v);
    ++cnt[uf.leader(u)];
  }

  rep(i, n) {
    ll leader = uf.leader(i);
    if (uf.size(leader) != cnt[leader]) {
      cout << "No" << '\n';
      return 0;
    }
  }

  cout << "Yes" << '\n';
  return 0;
}