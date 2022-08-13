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

  ll n = 15;
  vector<vector<ll>> grid(n, vector<ll>(n));

  rep(i, n/2) {
    rep(j, n/2) {
      if (i == 0) grid[i][j] = 1;
      else if (i == 1 and (j == 0 or j == n-1)) grid[i][j] = 1;
      else if (i == 2) {
        if (j == 1 or j == n-2) continue;
        grid[i][j] = 1;
      }
      else if (i == 3) {
        if (j == 0 or j == 2 or j == n-3 or j == n-1) grid[i][j] = 1;
      }
      else if (i == 4) {
        if (j == 1 or j == 3 or j == n-4 or j == n-2) continue;
        grid[i][j] = 1;
      }
      else if (i == 5) {
        if (j == 0 or j == 4 or j == n-5 or j == n-3 or j == n-1) {
          grid[i][j] = 1;
        }
      }
      else if (i == 6) {
        if (j == 1 or j == 3 or j == 5 or j == n-6 or j == n-4 or j == n-2) {
          continue;
        }
        grid[i][j] = 1;
      }
      else {
        if (j % 2 == 0) grid[i][j] = 1;
      }
    }
  }

  ll r, c;
  cin >> r >> c;
  --r; --c;
  if (r > n/2) {
    r = n - 1 - r;
  }

  if (grid[r][c]) print("black");
  else print("white");
  return 0;
}