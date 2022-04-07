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
  
  map<ll, ll> cnt;

  // dfs
  auto dfs = [&](auto dfs, ll v, ll p) -> void {
    if (cnt[c[v]] == 0) good[v] = true;

    ++cnt[c[v]];
    for (auto to : edge[v]) {
      if (to == p) continue;

      dfs(dfs, to, v);
    }

    --cnt[c[v]];
  };
  
  dfs(dfs, 0, -1);

  rep(i, n) {
    if (good[i]) cout << i+1 << "\n";
  }
  return 0;
}