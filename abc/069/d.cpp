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
  ll h, w;
  cin >> h >> w;

  ll n;
  cin >> n;

  using P = pair<ll, ll>;
  vector<P> cnt;
  rep(i, n) {
    ll a;
    cin >> a;
    cnt.emplace_back(a, i);
  }
  sort(cnt.rbegin(), cnt.rend());

  vector color(h, vector<ll>(w));

  ll i = 0; ll j = 0;
  ll di = 1;
  for (auto [a, idx] : cnt) {
    while (a > 0) {
      color[i][j] = idx + 1;

      --a;
      i += di;

      if (di == 1 and i == h) {
        i = h - 1;
        ++j;
        di = -1;
      }
      if (di == -1 and i == -1) {
        i = 0;
        ++j;
        di = 1;
      }
    }
  }

  print(color);
  return 0;
}