#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;


int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  // div_cnt[i] iの約数の個数
  vector<ll> div_cnt(n + 1);
  for (int i = 1; i <= n; ++i) {
    // iの倍数の個数をインクリメント
    for (int j = i; j <= n; j += i) {
      ++div_cnt[j];
    }
  }

  ll ans = 0;
  for (int i = 0; i <= n; ++i) {
    ans += i * div_cnt[i];
  }

  cout << ans << "\n";
  return 0;
}