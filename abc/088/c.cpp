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
  ll n = 3;

  vector c(n, vector<ll>(n));
  rep(i, n) rep(j, n) cin >> c[i][j];

  for (ll a0 = -100; a0 <= 100; ++a0) {
    for (ll a1 = -100; a1 <= 100; ++a1) {
      for (ll a2 = -100; a2 <= 100; ++a2) {
        vector<ll> a = {a0, a1, a2};
        vector<bool> seen_b(3);
        vector<ll> b(n);
        bool ok = true;

        auto f = [&]() {
          rep(i, n) rep(j, n) {
            if (not seen_b[j]) {
              b[j] = c[i][j] - a[i];
              seen_b[j] = true;
            }
            else {
              if (b[j] != c[i][j] - a[i]) {
                ok = false;
                return;
              }
            }
        }
        };
        f();

        if (ok) {
          cout << "Yes" << '\n';
          // print(a);
          // print(b);
          return 0;
        }
      }
    }
  }

  cout << "No" << '\n';
  return 0;
}