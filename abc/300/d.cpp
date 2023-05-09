#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


// 変数の範囲を絞る
// 変数を固定する
// 高速な素数判定
// 累積和
// https://drken1215.hatenablog.com/entry/2023/05/03/201800


int main() {
  ll n;
  cin >> n;

  ll MAX_P = 1000000;

  // エラトステネス
  vector<bool> is_prime(MAX_P, true);
  is_prime[0] = is_prime[1] = false;
  for (ll i = 2; i < MAX_P; ++i) {
    if (not is_prime[i]) continue;
    for (ll j = 2*i; j < MAX_P; j += i) {
      is_prime[j] = false;
    }
  }

  // 素数の累積和をとる
  vector<ll> cnt(MAX_P + 1);
  rep(i, MAX_P) {
    if (is_prime[i]) cnt[i + 1] = cnt[i] + 1;
    else cnt[i + 1] = cnt[i];
  }

  ll ans = 0;
  for (ll a = 1; a*a*a*a*a <= n; ++a) {
    if (not is_prime[a]) continue;

    for (ll b = a+1; b*b*b <= n; ++b) {
      if (not is_prime[b]) continue;

      ll MAX_C = sqrt(n / a / a / b);

      // b+1 <= c <= max_cとなるようなcが存在する場合にカウント
      if (b+1 <= MAX_C) {
        ans += cnt[MAX_C + 1] - cnt[b + 1];
      }
    }
  }

  cout << ans << '\n';
  return 0;
}