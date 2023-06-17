#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
#include <queue>
#include <map>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using ll = long long;
using namespace std;
#include <atcoder/dsu>
using namespace atcoder;


void print() { cout << '\n'; }
template<class T> void print(const T& value) { cout << value << '\n'; }
template<class T, class... A> void print(const T& first, const A&... tail) { cout << first << " "; print(tail...); }
template<class... A> void print(const A&... tail) { print(tail...); }
template<class T> void print(vector<T>& vec) { for (const auto& a : vec) { cout << a << " "; } print(); }


struct Coordinate {
  ll x, y;
  Coordinate(ll x_ = 0, ll y_ = 0) : x(x_), y(y_) {};
};


struct Solver {
  const ll inf = 1ll << 60;

  ll n, m, k;
  vector<Coordinate> broadcasters;
  vector<vector<pair<ll, ll>>> edge;
  vector<Coordinate> residents;
  dsu uf;
  map<pair<ll, ll>, ll> edge_idx;

  vector<ll> p;
  vector<bool> b;
  vector<ll> dist;
  vector<ll> prev;

  Solver(ll n_, ll m_, ll k_, vector<Coordinate> broadcasters_,
          vector<vector<pair<ll,ll>>> edge_, vector<Coordinate> residents_, dsu uf_,
          map<pair<ll, ll>, ll> edge_idx_)
        : n(n_), m(m_), k(k_), broadcasters(broadcasters_), edge(edge_),
          residents(residents_), uf(uf_), edge_idx(edge_idx_), p(vector<ll>(n, 0)), b(vector<bool>(m, false)),
          dist(vector<ll>(n, inf)), prev(vector<ll>(n, -1)) {};

  void connect(ll v) {
    vector<ll> path;
    for (ll cur = v; cur != -1; cur = prev[cur]) {
      path.emplace_back(cur);
    }

    ll len = path.size();
    rep(i, len-1) {
      // path[i], path[i+1]を結ぶ辺をONにする
      b[edge_idx[{path[i], path[i+1]}]] = true;
    }
  }

  void dijkstra() {
    dist[0] = 0;

    using P = pair<ll, ll>;
    priority_queue<P, vector<P>, greater<P>> heap;
    heap.emplace(dist[0], 0);

    while (not heap.empty()) {
      auto [d, v] = heap.top();
      heap.pop();

      if (dist[v] < d) continue;

      for (auto [to, w] : edge[v]) {
        if (dist[to] > dist[v] + w) {
          dist[to] = dist[v] + w;
          prev[to] = v;
          heap.emplace(dist[to], to);
        }
      }
    }
  }
  
  void solve() {
    for (auto resident : residents) {
      // 各住民から最短の放送局の出力強度をその距離に設定
      ll min_dist = 1ll << 60;
      ll near_broadcaster = 0;
      
      rep(i, n) {
        // atcoderオフィスと繋がっていない放送局はスキップ
        if (not uf.same(0, i)) continue;

        Coordinate broadcaster = broadcasters[i];
        ll eps = 1;
        ll dist = llround(sqrt((broadcaster.x-resident.x) * (broadcaster.x-resident.x)
                              + (broadcaster.y-resident.y) * (broadcaster.y-resident.y))) + eps;

        if (min_dist > dist) {
          min_dist = dist;
          near_broadcaster = i;
        }
      }

      // 出力強度をその距離に設定
      if (p[near_broadcaster] < min_dist) {
        p[near_broadcaster] = min_dist;
      }
    }

    // ケーブルのスイッチを設定
    dijkstra();
    rep(i, n) {
      if (p[i] == 0) continue;

      // 0 ~ iまでの頂点を接続したい
      connect(i);
    }

    // 答えを出力
    print(p);
    print(b);
  }
};


int main() {
  ll n, m, k;
  cin >> n >> m >> k;

  vector<Coordinate> broadcasters;
  rep(i, n) {
    ll x, y;
    cin >> x >> y;
    broadcasters.emplace_back(x, y);
  }

  vector edge(m, vector<pair<ll, ll>>());
  dsu uf(n);
  map<pair<ll, ll>, ll> edge_idx;
  rep(i, m) {
    ll u, v, w;
    cin >> u >> v >> w;
    --u; --v;

    edge[v].emplace_back(u, w);
    edge[u].emplace_back(v, w);

    uf.merge(u, v);

    edge_idx[{u, v}] = i;
    edge_idx[{v, u}] = i;
  }

  vector<Coordinate> residents;
  rep(i, k) {
    ll a, b;
    cin >> a >> b;
    residents.emplace_back(a, b);
  }

  Solver solver(n, m, k, broadcasters, edge, residents, uf, edge_idx);
  solver.solve();
  return 0;
}