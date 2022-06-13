#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdint>
#include <deque>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
#define rng(a) (a).begin(),(a).end()
#define rrng(a) (a).rbegin(),(a).rend()
using namespace std;
using ll = long long;
using P = pair<long long, long long>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;


int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  ll n, m;
  cin >> n >> m;

  vector<vector<ll>> edge(n);
  rep(i, m) {
    ll a, b;
    cin >> a >> b;
    --a; --b;
    edge[a].emplace_back(b);
    edge[b].emplace_back(a);
  }

  ll q;
  cin >> q;

  while (q--) {
    ll x, k;
    cin >> x >> k;
    --x;

    deque<ll> que;
    que.emplace_back(x);
    
    map<ll, ll> dist;

    set<ll> seen;
    seen.insert(x);
    
    while (!que.empty()) {
      auto v = que.front(); que.pop_front();

      for (auto to : edge[v]) {
        if (seen.count(to)) continue;

        dist[to] = dist[v] + 1;
        if (dist[to] <= k) {
          seen.insert(to);
          que.emplace_back(to);
        }
      }
    }

    ll ans = 0;
    for (auto v : seen) ans += v+1;
    cout << ans << "\n";
  }
  return 0;
}