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
#include <string>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(x) (x).begin(),(x).end()
using namespace std;
using ll = long long;
using P = pair<long long, long long>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;


ll calc(const vector<ll>& b, ll x, ll y) {
  ll res = 0;
  ll len_b = (ll)b.size();
  ll r = 0;
  map<ll, ll>  cnt;

  for (ll l = 0; l < len_b; ++l) {
    while (r < len_b && (cnt[x] == 0 || cnt[y] == 0)) {
      if (b[r] == x) ++cnt[x];
      if (b[r] == y) ++cnt[y];

      ++r;
    }

    if (cnt[x] >= 1 && cnt[y] >= 1) {
      res += len_b - r + 1;
    }

    if (b[l] == x) --cnt[x];
    if (b[l] == y) --cnt[y];
  }

  return res;
}


int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  ll n, x, y;
  cin >> n >> x >> y;

  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  // 条件を満たす部分列を求める
  ll i = 0;
  ll ans = 0;
  while (i < n) {
    vector<ll> b;

    while (i < n && (y <= a[i] && a[i] <= x)) {
      b.emplace_back(a[i]);
      ++i;
    }

    ans += calc(b, x, y);
    ++i;
  }

  cout << ans << "\n";
  return 0;
}