#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdint>
#include <deque>
#include <iostream>
#include <map>
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


int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  ll n, m, q;
  cin >> n >> m >> q;

  vector<ll> a(q), b(q), c(q), d(q);
  rep(i, q) {
    cin >> a[i] >> b[i] >> c[i] >> d[i];
    --a[i]; --b[i];
  }

  ll ans = 0;

  auto dfs = [&](auto dfs, vector<ll> A) -> void {
    if (A.size() == n) {
      ll sum = 0;
      rep(i, q) {
        if (A[b[i]] - A[a[i]] == c[i]) sum += d[i];
      }
      chmax(ans, sum);
      return;
    }

    for (ll i = A.back(); i <= m; ++i) {
      vector<ll> B = A;
      B.emplace_back(i);
      dfs(dfs, B);
    }
  };

  for (ll i = 1; i <= m; ++i) {
    vector<ll> v;
    v.emplace_back(i);
    dfs(dfs, v);
  }

  cout << ans << "\n";
  return 0;
}