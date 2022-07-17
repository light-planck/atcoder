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

  ll n, k;
  cin >> n >> k;

  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  vector<ll> b(n);
  rep(i, n) cin >> b[i];

  // dp_a[i]: xのi番目まで決めたとき、i番目にaを選ぶか
  vector<bool> dp_a(n + 1);
  dp_a[1] = true;

  vector<bool> dp_b(n + 1);
  dp_b[1] = true;

  for (int i = 1; i < n; ++i) {
    if (dp_a[i]) {
      if (abs(a[i-1] - a[i]) <= k) {
        dp_a[i + 1] = true;
      }
      if (abs(a[i-1] - b[i]) <= k) {
        dp_b[i + 1] = true;
      }
    }

    if (dp_b[i]) {
      if (abs(b[i-1] - a[i]) <= k) {
        dp_a[i + 1] = true;
      }
      if (abs(b[i-1] - b[i]) <= k) {
        dp_b[i + 1] = true;
      }
    }
  }

  if (dp_a[n] || dp_b[n]) cout << "Yes" << "\n";
  else cout << "No" << "\n";
  return 0;
}