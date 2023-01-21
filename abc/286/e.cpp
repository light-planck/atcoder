#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  ll n;
  cin >> n;

  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  vector<string> s(n);
  rep(i, n) cin >> s[i];

  constexpr ll inf = 1ll << 60;
  vector dist(n, vector<ll>(n, 0));
  vector path(n, vector<ll>(n));
  rep(i, n) rep(j, n) {
    if (s[i][j] == 'Y') dist[i][j] = a[j];

    // if (i == j) dist[i][j] = 0;
    // else if (s[i][j] == 'Y') {
    //   dist[i][j] = a[j];
    // }
  }
  rep(k, n) rep(i, n) rep(j, n) {
    auto chmax = [](auto& a, auto b) { if (a < b) a = b; };
    // auto chmin = [](auto& a, auto b) { if (a > b) a = b; };
    chmax(dist[i][j], dist[i][k]+dist[k][j]);
  }

  ll q;
  cin >> q;

  while (q--) {
    ll u, v;
    cin >> u >> v;
    --u; --v;

    if (dist[u][v] == inf) cout << "Impossible" << '\n';
    else cout << path[u][v] << " " << dist[u][v]+a[u] << '\n';
  }
  return 0;
}