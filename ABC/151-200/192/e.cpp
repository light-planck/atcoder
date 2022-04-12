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


const ll inf = 1e18;
struct Edge {
  ll to;
  ll cost;
  ll k;

  Edge(ll to, ll cost, ll k) : to(to), cost(cost), k(k) {}
};


void dijkstra(vector<vector<Edge>>& edges, ll s, vector<ll>& dist) {
  ll n = edges.size();

  dist.resize(n, inf);
  dist[s] = 0;

  priority_queue<P, vector<P>, greater<P>> heap;
  heap.emplace(dist[s], s);

  while (!heap.empty()) {
    ll v = heap.top().second;
    ll dist_v = heap.top().first;
    heap.pop();

    // 更新しない
    if (dist_v > dist[v]) continue;

    for (auto &edge : edges[v]) {
      ll new_dist = edge.k * (dist_v + edge.k - 1) / edge.k + edge.to;
      if (dist[edge.to] > new_dist) {
        dist[edge.to] = new_dist;
        heap.emplace(dist[edge.to], edge.to);
      }
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

  vector<ll> dist;

  dijkstra(edges, x, dist);

  ll ans = dist[y];
  if (ans == inf) ans = -1;
  cout << ans << "\n";
  return 0;
}