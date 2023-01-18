#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n, m, r;
  cin >> n >> m >> r;

  vector<ll> town(r);
  rep(i, r) cin >> town[i], --town[i];
  sort(town.begin(), town.end());

  // ワーシャルフロイド
  constexpr ll inf = 1ll << 60;
  vector dist(n, vector<ll>(n, inf));
  rep(i, n) dist[i][i] = 0;
  rep(i, m) {
    ll a, b, c;
    cin >> a >> b >> c;
    --a; --b;
    dist[a][b] = c;
    dist[b][a] = c;
  }
  rep(k, n) rep(i, n) rep(j, n) {
    auto chmin = [](auto& a, auto b) { if (a > b) a = b; };
    chmin(dist[i][j], dist[i][k]+dist[k][j]);
  }

  ll ans = 1ll << 60;
  do {
    ll cost = 0;
    ll now = town[0];

    for (auto to : town) {
      cost += dist[now][to];
      now = to;
    }

    auto chmin = [](auto& a, auto b) { if (a > b) a = b; };
    chmin(ans, cost);
  } while (next_permutation(town.begin(), town.end()));

  cout << ans << '\n';
  return 0;
}