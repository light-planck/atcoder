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
inline bool chmax(ll& a, ll b) { if (a < b) { a = b; return 1; } return 0; }
inline bool chmin(ll& a, ll b) { if (a > b) { a = b; return 1; } return 0; }
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;


int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  ll n, l, r;
  cin >> n >> l >> r;

  vector<ll> a(n);
  rep(i, n) cin >> a[i];


  // left
  vector<ll> left(n + 1);
  rep(i, n) left[i + 1] = left[i] + a[i];
  ll x = 0;
  ll max_ds = 0;
  for (ll i = 1; i <= n; ++i) {
    ll ds = left[i] - l*i;
    if (ds >= max_ds) {
      max_ds = ds;
      x = i;
    }
  }
  rep(i, x) a[i] = l;


  // right
  vector<ll> right(n + 1);
  rep(i, n) right[i + 1] = right[i] + a[n - 1 - i];
  ll y = 0;
  max_ds = 0;
  for (ll i = 1; i <= n; ++i) {
    ll ds = right[i] - r*i;
    if (ds >= max_ds) {
      max_ds = ds;
      y = i;
    }
  }
  rep(i, y) a[n - 1 - i] = r;


  ll ans = 0;
  rep(i, n) ans += a[i];
  print(ans);
  return 0;
}