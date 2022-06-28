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

  ll n, k, q;
  cin >> n >> k >> q;

  vector<ll> a(k);
  rep(i, k) cin >> a[i];

  vector<ll> l(q);
  rep(i, q) cin >> l[i];

  vector<ll> grid(n + 1);
  for (auto x : a) grid[x] = 1;

  rep(i, q) {
    ll cnt = 0;
    ll idx = 0;

    rep(j, n+1) {
      if (grid[j]) ++cnt;

      if (cnt == l[i]) {
        idx = j;
        break;
      }
    }

    if (idx+1 <= n and grid[idx + 1] == 0) {
      grid[idx + 1] = 1;
      grid[idx] = 0;
    }
  }

  rep(i, n+1) {
    if (grid[i]) cout << i << " ";
  }
  cout << "\n";
  return 0;
}