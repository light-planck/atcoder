#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


// 嬉しい列は文字の個数が全て偶数。
// sの[l, r]の文字列を考えたとき、lを固定してrを動かしていくとO(N**2)で間に合わない。
// 尺取り法も単調性を満たさないので使えない。
// i文字目まで見たときの文字の個数を左から数えていって累積和を取る。
// s[i]とs[j]の全ての文字の個数の偶奇が同じなら[i, j]は嬉しい文字列となる。
// 個数の偶奇が分かればいいので、個数は偶奇の0, 1で考える。
// 個数の分布をvectorかbitで持ち、それらの個数から2つの区間の端を選び加算していく。


int main() {
  string s;
  cin >> s;

  ll n = s.size();
  vector sum(n+1, 0ll);

  rep(i, n) {
    ll d = s[i] - '0';
    sum[i+1] = sum[i];
    sum[i+1] ^= 1<<d;
  }

  map<ll, ll> cnt;
  for (auto x : sum) ++cnt[x];

  ll ans = 0;
  for (auto [x, y] : cnt) ans += (y-1)*y / 2;
  cout << ans << '\n';
  return 0;
}