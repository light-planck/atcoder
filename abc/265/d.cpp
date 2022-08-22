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

  vector<ll> aims(3);
  rep(i, 3) cin >> aims[i];

  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  ll left = 0; ll right = 0;
  ll cur = 0; ll aim = aims[cur];
  ll sum = 0;
  while (right < n) {
    sum += a[right];

    if (sum > aim) {
      while (sum > aim and left < n) {
        sum -= a[left];
        ++left;
      }

      aim = aims[cur];
    }

    if (sum == aim) {
      if (cur == 2) {
        cout << "Yes" << '\n';
        return 0;
      }

      sum = 0;
      ++cur;
      aim = aims[cur];
      left = right + 1;
    }

    ++right;
  }

  cout << "No" << '\n';
  return 0;
}