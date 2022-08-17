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
void print(vector<P>& vp) { for (auto [x, y] : vp) print(x, y); }
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

  ll n;
  cin >> n;

  vector<ll> v(n);
  rep(i, n) cin >> v[i];

  // 偶数番目と奇数番目の値の出現回数をチェック
  // [v, cnt]
  map<ll, ll> even_cnt; map<ll, ll> odd_cnt;
  rep(i, n) {
    if (i & 1) ++odd_cnt[v[i]];
    else ++even_cnt[v[i]];
  }

  // 出現回数が多い順にソート
  // [cnt, v]
  vector<P> even; vector<P> odd;
  for (auto [x, cnt] : even_cnt) even.emplace_back(cnt, x);
  for (auto [x, cnt] : odd_cnt) odd.emplace_back(cnt, x);
  even.emplace_back(0, 0);
  odd.emplace_back(0, 0);
  sort(rrng(even)); sort(rrng(odd));

  // 出現頻度の多い値が異なるならばそれを書き換える
  if (even[0].second != odd[0].second) {
    print(n/2 - even[0].first + n/2 - odd[0].first);
    return 0;
  }

  // そうでないならば偶数と奇数番目の値の頻度の高い2つの値から
  // 最小の操作回数となるような組み合わせを見つける
  constexpr ll inf = 9e18;
  ll ans = inf;
  rep(i, 2) rep(j, 2) {
    if (i == 0 and j == 0) continue;

    auto [cnt1, e] = even[i];
    auto [cnt2, o] = odd[j];
    ll tmp = n/2 - cnt1 + n/2 - cnt2;
    chmin(ans, tmp);
  }

  print(ans);
  return 0;
}