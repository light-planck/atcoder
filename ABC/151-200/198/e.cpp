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
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;
// using mint = modint1000000007;


int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  ll n;
  cin >> n;

  vector<ll> c(n);
  rep(i, n) cin >> c[i];

  vector<vector<ll>> edge(n);
  rep(i, n-1) {
    ll a, b;
    cin >> a >> b;
    --a; --b;
    edge[a].emplace_back(b);
    edge[b].emplace_back(a);
  }

  // 良い頂点か
  vector<bool> good(n);
  
  // 頂点の色の集合
  set<ll> seen_color;

  // bfs
  vector<ll> dist(n, -1);
  dist[0] = 0;
  queue<ll> que;
  que.push(0);
  
  while (que.size()) {
    ll v = que.front();
    que.pop();

    // 良い頂点か判定
    if (!seen_color.count(c[v])) {
      good[v] = true;
      seen_color.insert(c[v]);
    }

    for (auto to : edge[v]) {
      if (dist[to] != -1) continue;

      dist[to] = dist[v] + 1;
      que.push(to);
    }
  }

  rep(i, n) {
    if (good[i]) cout << i+1 << "\n";
  }
  return 0;
}