#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(x) (x).begin(),(x).end()
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;
// using mint = modint1000000007;


// dp[i][j][l]: 頂点sからi回移動したときの頂点がjである
// 選び方の総和(xを通った回数の偶奇をl=0, 1)
mint dp[2010][2010][2];

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  ll n, m, k, s, t, x;
  cin >> n >> m >> k >> s >> t >> x;
  --s; --t; --x;

  vector<vector<ll>> edge(n);
  rep(i, m) {
    ll u, v;
    cin >> u >> v;
    --u; --v;
    edge[u].emplace_back(v);
    edge[v].emplace_back(u);
  }

  dp[0][s][0] = 1;

  rep(i, k) {
    for (auto to : edge[i]) {
      
    }
  }

  cout << dp[k][t][0].val() << "\n";
  return 0;
}