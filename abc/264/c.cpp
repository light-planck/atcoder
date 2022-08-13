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
using P = pair<ll, ll>;
void print() { cout << '\n'; }
template<class T> void print(const T& value) { cout << value << '\n'; }
template<class T, class... A> void print(const T& first, const A&... tail) { cout << first << " "; print(tail...); }
template<class... A> void print(const A&... tail) { print(tail...); }
template<class T> void print(vector<T>& vec) { for (const auto& a : vec) { cout << a << " "; } print(); }
template<class T> void print(vector<vector<T>>& vec2d) { for (auto& vec : vec2d) { print(vec); } }
void print(vector<string>& grid) { for (const auto& row : grid) print(row); }
template<class T, class U> void print(const map<T, U>& mp) { for (const auto& [x, y] : mp) { print(x, y); } }
template<class T> void print(set<T>& st) { for (const auto& a : st) { cout << a << " "; } print(); }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
inline bool chmax(ll& a, ll b) { if (a < b) { a = b; return 1; } return 0; }
inline bool chmin(ll& a, ll b) { if (a > b) { a = b; return 1; } return 0; }
auto max(ll a, ll b) { if (a > b) return a; else return b; }
auto min(ll a, ll b) { if (a < b) return a; else return b; }
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;


int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  ll h1, w1;
  cin >> h1 >> w1;
  vector<vector<ll>> a(h1, vector<ll>(w1));
  rep(i, h1) rep(j, w1) cin >> a[i][j];

  ll h2, w2;
  cin >> h2 >> w2;
  vector<vector<ll>> b(h2, vector<ll>(w2));
  rep(i, h2) rep(j, w2) cin >> b[i][j];

  auto dfs = [&](auto dfs, vector<vector<ll>> x) -> void {
    ll h = x.size();
    ll w = x[0].size();

    if (h == h2 and w == w2) {
      if (x == b) {
        cout << "Yes" << '\n';
        return;
      }
    }
    if (h < h2 or w < w2) return;

    rep(hi, h) {
      vector<vector<ll>> y;
      rep(i, h) {
        if (hi == i) continue;
        rep(j, w) {
          y.emplace_back(x[i]);
        }
      }
      dfs(dfs, y);
    }

    rep(wi, w) {
      vector<vector<ll>> y;
      rep(j, w) {
        if (j == wi) continue;
        rep(i, h) y[i].emplace_back(x[i][j]);
      }
      dfs(dfs, y);
    }
  };

  dfs(dfs, a);
  cout << "No" << '\n';
  return 0;
}