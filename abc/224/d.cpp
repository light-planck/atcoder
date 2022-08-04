#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <deque>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
#define rng(a) (a).begin(),(a).end()
#define rrng(a) (a).rbegin(),(a).rend()
using namespace std;
using ll = long long;
using P = pair<long long, long long>;
void print() { cout << "\n"; }
template<class T> void print(const T& value) { cout << value << "\n"; }
template<class T, class... A> void print(const T& first, const A&... tail) { cout << first << " "; print(tail...); }
template<class... A> void print(const A&... tail) { print(tail...); }
template<class T> void print(vector<T>& vec) { for (const auto& a : vec) { cout << a << " "; } print(); }
template<class T> void print(vector<vector<T>>& vec2d) { for (auto& vec : vec2d) { print(vec); } }
void print(vector<string>& grid) { for (const auto& row : grid) print(row); }
template<class T, class U> void print(const map<T, U>& mp) { for (const auto& [x, y] : mp) { print(x, y); } }
template<class T> void print(set<T>& st) { for (const auto& a : st) { cout << a << " "; } print(); }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;


int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  ll m;
  cin >> m;

  ll n = 9;

  vector<vector<ll>> edge(n);
  rep(i, m) {
    ll u, v;
    cin >> u >> v;
    --u; --v;
    edge[u].emplace_back(v);
    edge[v].emplace_back(u);
  }

  ll k = 8;
  vector<ll> s(n, -1);
  rep(i, k) {
    ll p;
    cin >> p;
    --p;
    s[p] = i;
  }

  map<vector<ll>, ll> dist;
  dist[s] = 0;

  deque<vector<ll>> que;
  que.emplace_back(s);

  while (not que.empty()) {
    auto state = que.front(); que.pop_front();

    // コマがない頂点
    ll v = 0;
    rep(i, n) if (state[i] == -1) v = i;

    for (auto to : edge[v]) {
      auto next_state = state;
      swap(next_state[v], next_state[to]);
      if (dist.count(next_state)) continue;

      dist[next_state] = dist[state] + 1;
      que.emplace_back(next_state);
    }
  }

  vector<ll> t(n, -1);
  rep(i, k) t[i] = i;

  if (not dist.count(t)) print(-1);
  else print(dist[t]);
  return 0;
}