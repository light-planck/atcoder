#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  ll n, k;
  cin >> n >> k;

  ll log_k = 1;
  while ((1LL << log_k) <= k) ++log_k;

  vector<vector<ll>> db(log_k + 1, vector<ll>(n));
  rep(i, n) {
    cin >> db[0][i];
    --db[0][i];
  }

  rep(i, log_k) {
    rep(j, n) {
      db[i + 1][j] = db[i][db[i][j]];
    }
  }

  ll now = 0;
  for (int i = 0; k > 0; i++) {
    if (k & 1) now = db[i][now];
    k >>= 1;
  }

  cout << now + 1 << "\n";
  return 0;
}