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

  vector<ll> l(n), r(n);
  rep(i, n) cin >> l[i] >> r[i];

  constexpr ll mx = 2e5+5;
  vector<ll> pos(mx);

  rep(i, n) {
    ++pos[l[i]];
    --pos[r[i]];
  }

  for (ll i = 1; i < mx; ++i) {
    pos[i] += pos[i - 1];
  }

  ll left = -1;
  ll right = 0;
  vector<P> lr;
  ll cnt = 0;

  for (ll i = 1; i < mx; ++i) {
    if (pos[i] >= 1 and cnt == 0) {
      left = i;
      ++cnt;
    }
    if (pos[i] == 0 and cnt == 1) {
      right = i;
      lr.emplace_back(left, right);
      cnt = 0;
    }
  }

  for (auto [x, y] : lr) {
    cout << x << " " << y << "\n";
  }
  return 0;
}