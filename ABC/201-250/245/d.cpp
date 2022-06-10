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


int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  ll n, m;
  cin >> n >> m;

  vector<ll> a(n + 1);
  rep(i, n+1) cin >> a[i];

  vector<ll> c(n + m + 1);
  rep(i, n+m+1) cin >> c[i];

  vector<ll> b(m + 1);

  for (int i = m; i >= 0; --i) {
    b[i] = c[n + i] / a[n];

    rep(j, n+1) {
      c[n + i - j] -= b[i] * a[n - j];
    }
  }

  for (auto x : b) cout << x << "\n";
  return 0;
}