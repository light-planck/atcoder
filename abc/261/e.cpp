#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdint>
#include <deque>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
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

  ll n, c;
  cin >> n >> c;

  vector<P> ta;
  rep(_, n) {
    ll t, a;
    cin >> t >> a;
    ta.emplace_back(t, a);
  }

  vector<ll> ans(n);
  rep(k, 30) {
    ll x_dig = (c>>k) & 1;
    ll composite[] = {0, 1};

    rep(i, n) {
      auto [t, a] = ta[i];
      ll a_dig = (a>>k) & 1;
      ll f[2];

      rep(j, 2) {
        if (t == 1) f[j] = j & a_dig;
        if (t == 2) f[j] = j | a_dig;
        if (t == 3) f[j] = j ^ a_dig;
      }

      rep(j, 2) composite[j] = f[composite[j]];
      x_dig = composite[x_dig];
      ans[i] |= x_dig << k;
    }
  }

  print(ans);
  return 0;
}