#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


// 変数の範囲を絞る
// 変数を固定する
// 高速な素数判定
// 累積和
// https://drken1215.hatenablog.com/entry/2023/05/03/201800


struct Sieve {
  private:
    int n_;
    vector<bool> is_prime_;

  public:
    Sieve(int n) : n_(n), is_prime_(vector<bool>(n_+1, true)) {
      is_prime_[0] = false;
      is_prime_[1] = false;
      for (long long i = 2; i*i <= n_; ++i) {
        if (not is_prime_[i]) continue;
        for (long long j = i*i; j <= n_; j += i) {
          is_prime_[j]= false;
        }
      }
    }

    bool is_prime(int x) {
      return is_prime_[x];
    }
};


int main() {
  ll n;
  cin >> n;

  const ll MAX_P = 1000000;

  // エラトステネス
  Sieve sieve(MAX_P);

  // 素数の累積和をとる
  vector<ll> cnt(MAX_P + 1);
  rep(i, MAX_P) {
    if (sieve.is_prime(i)) cnt[i + 1] = cnt[i] + 1;
    else cnt[i + 1] = cnt[i];
  }

  ll ans = 0;
  for (ll a = 1; a*a*a*a*a <= n; ++a) {
    if (not sieve.is_prime(a)) continue;

    for (ll b = a+1; b*b*b <= n; ++b) {
      if (not sieve.is_prime(b)) continue;

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