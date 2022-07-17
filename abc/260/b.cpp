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

  ll n, x, y, z;
  cin >> n >> x >> y >> z;

  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  vector<ll> b(n);
  rep(i, n) cin >> b[i];

  vector<P> a_idx;
  rep(i, n) {
    a_idx.emplace_back(a[i], -i);
  }
  sort(rrng(a_idx));

  vector<P> b_idx;
  rep(i, n) {
    b_idx.emplace_back(b[i], -i);
  }
  sort(rrng(b_idx));

  vector<P> ab_idx;
  rep(i, n) {
    ab_idx.emplace_back(a[i]+b[i], -i);
  }
  sort(rrng(ab_idx));

  set<ll> seen;
  for (auto [ai, idx] : a_idx) {
    if (x == 0) break;;
    idx = -1*idx + 1;
    if (seen.count(-idx)) continue;

    seen.insert(idx);
    // cout << "a: " << idx << "\n";
    --x;
  }

  for (auto [bi, idx] : b_idx) {
    if (y == 0) break;
    idx = -1*idx + 1;
    if (seen.count(idx)) continue;

    seen.insert(idx);
    // cout << "b: " << idx << "\n";
    
    --y;
  }

  for (auto [abi, idx] : ab_idx) {
    if (z == 0) break;
    idx = -1*idx + 1;
    if (seen.count(idx)) continue;

    seen.insert(idx);
    // cout << "ab: " << idx << "\n";

    --z;
  }

  for (auto idx : seen) cout << idx << "\n";

  // for (auto [ai, idx] : a_idx) {
  //   cout << idx << " " << ai << "\n";
  // }
  return 0;
}