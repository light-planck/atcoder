#include <bits/stdc++.h>
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
  ll h, w;
  cin >> h >> w;

  vector a(h, vector<ll>(w));
  rep(i, h) rep(j, w) cin >> a[i][j];
  
  vector<tuple<ll, ll, ll, ll>> ans;

  rep(i, h) rep(j, w) {
    if (a[i][j] & 1) {
      if (j + 1 < w) {
        --a[i][j];
        ++a[i][j + 1];
        ans.emplace_back(i, j, i, j+1);
      }
    }
  }

  rep(i, h) {
    if (a[i][w - 1] & 1) {
      if (i + 1 < h) {
        --a[i][w - 1];
        ++a[i + 1][w - 1];
        ans.emplace_back(i, w-1, i+1, w-1);
      }
    }
  }

  cout << ans.size() << '\n';
  for (auto [i, j, ni, nj] : ans) {
    print(i+1, j+1, ni+1, nj+1);
  }
  return 0;
}