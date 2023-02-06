#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;
#include <atcoder/dsu>
using namespace atcoder;


int main() {
  ll n, m;
  cin >> n >> m;

  vector<ll> cnt(n);
  rep(i, m) {
    ll u, v;
    cin >> u >> v;
    --u; --v;

    ++cnt[u];
    ++cnt[v];
  }

  bool ok = true;
  ll edge = 0;
  rep(i, n) {
    if (cnt[i] == 1) ++edge;
    else if (cnt[i] != 2) ok = false;
  }
  if (edge != 2) ok = false;
  
  if (ok) cout << "Yes" << '\n';
  else cout << "No" << '\n'; 
  return 0;
}