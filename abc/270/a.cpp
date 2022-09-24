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
  ll a, b;
  cin >> a >> b;

  vector<ll> points = {1, 2, 4};
  map<ll, vector<ll>> mp;

  for (ll bit = 0; bit < (1<<3); ++bit) {
    vector<ll> idx;
    ll sum = 0;

    rep(i, 3) {
      if ((bit>>i) & 1) {
        idx.emplace_back(i);
        sum += points[i];
      }
    }

    mp[sum] = idx;
  }

  vector<ll> ai = mp[a];
  vector<ll> bi = mp[b];

  set<ll> st;
  for (auto i : ai) st.emplace(i);
  for (auto i : bi) st.emplace(i);

  ll ans = 0;
  for (auto i : st) {
    ans += points[i];
  }

  cout << ans << '\n';
  return 0;
}