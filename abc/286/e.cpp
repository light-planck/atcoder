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

  constexpr ll inf = 1ll << 60;
  vector dist(n, vector<ll>(n));
  rep(i, n) {
    string s;
    cin >> s;
    rep(j, n) {
      if (s[j] == 'Y') dist[i][j] = 1;
      else dist[i][j] = inf;
    }
  }

  vector val(n, vector<ll>(n));
  rep(i, n) rep(j, n) {
    val[i][j] = a[i];
  }

  rep(k, n) rep(i, n) rep(j, n) {
    if (dist[i][k]+dist[k][j] < dist[i][j]) {
      dist[i][j] = dist[i][k] + dist[k][j];
      val[i][j] = val[i][k] + val[k][j];
    }
    else if (dist[i][k]+dist[k][j] == dist[i][j]) {
      if (val[i][k]+val[k][j] > val[i][j]) {
        dist[i][j] = dist[i][k] + dist[k][j];
        val[i][j] = val[i][k] + val[k][j];
      }
    }
  }

  ll q;
  cin >> q;

  while (q--) {
    ll u, v;
    cin >> u >> v;
    --u; --v;
    if (dist[u][v] == inf) cout << "Impossible" << '\n';
    else cout << dist[u][v] << " " << val[u][v]+a[v] << '\n';
  }
  return 0;
}