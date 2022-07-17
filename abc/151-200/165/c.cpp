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


ll n, m, q;
ll a[50];
ll b[50];
ll c[50];
ll d[50];
ll ans = 0;


void dfs(const vector<ll>& perm) {
  if (perm.size() == n) {
    ll sum = 0;
    rep(i, q) {
      if (perm[b[i]] - perm[a[i]] == c[i]) sum += d[i];
    }

    chmax(ans, sum);
    return;
  }

  for (ll i = perm.back(); i <= m; ++i) {
    vector<ll> v = perm;
    v.emplace_back(i);
    dfs(v);
  }
}


int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> m >> q;
  rep(i, q) {
    cin >> a[i] >> b[i] >> c[i] >> d[i];
    --a[i]; --b[i];
  }

  for (ll i = 1; i <= m; ++i) {
    vector<ll> v;
    v.emplace_back(i);
    dfs(v);
  }

  cout << ans << "\n";
  return 0;
}