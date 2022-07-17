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
#include <atcoder/all>
using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;


int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  ll n, m, k;
  cin >> n >> m >> k;

  dsu uf(n);
  vector<vector<ll>> edge(n);
  rep(i, m) {
    ll a, b;
    cin >> a >> b;
    --a; --b;
    uf.merge(a, b);
    edge[a].emplace_back(b);
    edge[b].emplace_back(a);
  }

  vector<vector<ll>> block(n);
  rep(i, k) {
    ll c, d;
    cin >> c >> d;
    --c; --d;
    block[c].emplace_back(d);
    block[d].emplace_back(c);
  }

  rep(i, n) {
    ll ans = uf.size(uf.leader(i));
    --ans;

    ans -= edge[i].size();

    for (auto bk : block[i]) {
      if (uf.same(i, bk)) --ans;
    }

    cout << ans << "\n";
  }
  return 0;
}