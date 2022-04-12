#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower
#include <cmath> // abs, sqrt, cos, ...
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(x) (x).begin(),(x).end()
using namespace std;
using ll = long long;
using P = pair<long long, long long>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;
// using mint = modint1000000007;


struct Edge {
  ll to;
  ll cost;
  ll k;

  Edge(ll to, ll cost, ll k) : to(to), cost(cost), k(k) {}
};


void dijkstra(vector<vector<Edge>>& edges, ll s, vector<ll>& dist) {
  dist[s] = 0;

  priority_queue<P, vector<P>, greater<P>> heap;
  heap.emplace(0, s);

  while (!heap.empty()) {
    ll v = heap.top().second;
    ll dist_v = heap.top().first;
    heap.pop();

    // 更新しない
    if (dist[v] < dist_v) continue;

    for (auto edge : edges[v]) {

      // 切り上げは最初に計算する
      ll new_dist = ((dist_v + edge.k - 1) / edge.k) * edge.k + edge.cost;

      // 更新しない
      if (dist[edge.to] <= new_dist) continue;

      dist[edge.to] = new_dist;
      heap.emplace(dist[edge.to], edge.to);
    }
  }
}


int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  ll n, m, x, y;
  cin >> n >> m >> x >> y;
  --x; --y;

  // <to, cost, k>
  vector<vector<Edge>> edges(n);
  while (m--) {
    ll a, b, t, k;
    cin >> a >> b >> t >> k;
    --a; --b;
    edges[a].emplace_back(b, t, k);
    edges[b].emplace_back(a, t, k);
  }

  const ll inf = 1e18;
  vector<ll> dist(n, inf);

  dijkstra(edges, x, dist);

  if (dist[y] == inf) cout << -1 << "\n";
  else cout << dist[y] << "\n";
  return 0;
}