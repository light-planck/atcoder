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
#include <unordered_map>
#include <unordered_set>
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

  ll n;
  cin >> n;

  vector<ll> x(n), y(n), p(n);
  rep(i, n) cin >> x[i] >> y[i] >> p[i];

  
  auto judge = [&](ll s) -> bool {
    rep(i, n) {
      deque<ll> que;
      que.emplace_back(i);

      set<ll> seen;
      seen.insert(i);

      while (!que.empty()) {
        ll v = que.front();
        que.pop_front();

        rep(to, n) {
          if (to == v) continue;
          if (seen.count(to)) continue;

          if (p[v]*s >= abs(x[v]-x[to]) + abs(y[v]-y[to])) {
            seen.insert(to);
            que.emplace_back(to);
          }
        }
      }

      if (seen.size() == n) return true;
    }

    return false;
  };


  ll ng = 0;
  ll ok = 4e9;
  while (abs(ok-ng) > 1) {
    ll mid = (ng+ok) / 2;
    if (judge(mid)) ok = mid;
    else ng = mid;
  }

  cout << ok << "\n";
  return 0;
}