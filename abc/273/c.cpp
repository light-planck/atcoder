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
  ll n;
  cin >> n;

  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  set<ll> st;
  rep(i, n) st.emplace(a[i]);

  vector<ll> b;
  for (auto x : st) b.emplace_back(x);
  ll m = b.size();

  vector<ll> cnt(n);

  rep(i, n) {
    ll idx = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
    // cout << m - 1 - idx << '\n';
    ll c = m - 1 - idx;
    ++cnt[c];
  }

  rep(i, n) cout << cnt[i] << '\n';
}