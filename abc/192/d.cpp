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


// xをn進数から10進数に変換する
auto n2ten(string s, __int128_t n) {
  __int128_t res = 0;
  reverse(rng(s));
  __int128_t base = 1;

  for (auto c : s) {
    ll d = c - '0';
    res += d * base;
    base *= n;
  }

  return res;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  string s;
  cin >> s;

  ll m;
  cin >> m;

  ll d = 0;
  for (auto c : s) chmax(d, ll(c-'0'));

  ll ok = d;
  ll ng = m + 1;
  while (abs(ok-ng) > 1) {
    ll mid = (ok+ng) / 2;
  
    auto check = [&]() {
      return n2ten(s, mid) <= m;
    };
  
    if (check()) ok = mid;
    else ng = mid;
  }

  print(ok - d);
  return 0;
}