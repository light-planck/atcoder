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
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;


int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  // ll n, c;
  // cin >> n >> c;

  // vector<ll> t(n), a(n);
  // rep(i, n) cin >> t[i] >> a[i];

  // vector<ll> ans = {c};
  // ll prev = c;
  // rep(i, n) {
  //   ll now = 0;

  //   if (t[i] == 1) {
  //     now = ans.back() & a[i];
  //   }
  //   if (t[i] == 2) {
  //     now = ans.back() | a[i];
  //   }
  //   if (t[i] == 3) {
  //     now = ans.back() ^ a[i];
  //   }

  //   cout << now << "\n";
  //   ans.emplace_back(now);
  //   prev = now;
  // }

  ll res = (9 ^ 3) | 5;
  cout << res << "\n";
  return 0;
}