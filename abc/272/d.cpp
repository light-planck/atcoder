#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <deque>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


void print() { cout << '\n'; }
template<class T> void print(const T& value) { cout << value << '\n'; }
template<class T, class... A> void print(const T& first, const A&... tail) { cout << first << " "; print(tail...); }
template<class... A> void print(const A&... tail) { print(tail...); }
template<class T> void print(vector<T>& vec) { for (const auto& a : vec) { cout << a << " "; } print(); }
template<class T> void print(vector<vector<T>>& vec2d) { for (auto& vec : vec2d) { print(vec); } }
void print(vector<string>& grid) { for (const auto& row : grid) print(row); }
template<class T, class U> void print(const map<T, U>& mp) { for (const auto& [x, y] : mp) { print(x, y); } }
template<class T> void print(set<T>& st) { for (const auto& a : st) { cout << a << " "; } print(); }
void print(vector<pair<ll, ll>>& vp) { for (auto [x, y] : vp) print(x, y); }


int main() {
  ll n, m;
  cin >> n >> m;

  vector dist(n, vector<ll>(n, -1));
  vector seen(n, vector<bool>(n, false));

  auto dfs = [&](auto dfs, ll x, ll y, ll l) -> void {
    if (seen[x][y]) return;

    seen[x][y] = true;
    dist[x][y] = l;

    rep(i, n) for (ll j = i; j < n; ++j) {
      if (seen[i][j]) continue;

      ll d = (i-x)*(i-x) + (j-y)*(j-y);
      if (d == m) {
        dfs(dfs, i, j, l+1);
      }
    }
  };
  dfs(dfs, 0, 0, 0);

  rep(i, n) rep(j, n) {
    if (dist[i][j] == -1) dist[i][j] = dist[j][i];
  }

  print(dist);
  return 0;
}