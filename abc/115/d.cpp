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


// 1. 全探索できるか
// 2. 何が分かれば答えが求まるか
// 3. 数式に落とし込めるか
// 4. 重複する計算はあるか


int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  ll n, x;
  cin >> n >> x;

  vector<ll> a(n + 1);
  a[0] = 1;
  vector<ll> p(n + 1);
  p[0] = 1;
  rep(i, n) {
    a[i + 1] = 2*a[i] + 3;
    p[i + 1] = 2*p[i] + 1;
  }

  auto f = [&](auto f, ll level, ll i) -> ll {
    if (level == 0) return 1;

    ll len = a[level - 1];
    ll num = p[level - 1];

    if (i == 1) return 0;
    else if (i <= len + 1) return f(f, level-1, i-1);
    else if (i == len + 2) return num + 1;
    else if (i <= 2*len + 2) return num + 1 + f(f, level-1, i-len-2);
    else return 2*num + 1;
  };

  print(f(f, n, x));
  return 0;
}