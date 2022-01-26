#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;

const int kMod =  998244353;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  ll n;
  cin >> n;

  vector<ll> a(n), b(n);
  rep(i, n) cin >> a[i];
  rep(i, n) cin >> b[i];

  ll ans = 1;
  for (int ai = 0; ai < n; ++ai) {
    for (int bi = 0; bi < n; ++bi) {
      ans *= max(0, b[bi] - a[ai]);
      ans %= kMod;
    }
  }

  cout << ans << "\n";
  return 0;
}