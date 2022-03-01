#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;


/*
10^100は無視して、0, 1, 2, ..., nのn+1個の数を考える。
n = 3、k = 3を考える。
0, 1, 2, 3
の中から3つ選ぶと和は
3, 4, 5, 6の4通りである。
これは左端から3つ選んだときの和
l = 0 + 1 + 2 = 3と
右端から3つ選んだときの和
r = 1 + 2 + 3 = 6
の差r - l + 1 = 4である。
任意のkに対して和の個数は
l = 0 + 1 + ... + (k-1) = k * (k-1) / 2
r = n + n-1 + ... + (n-k+1) = k * (2n-k+1) / 2
cnt = r - l + 1となる。
これをk <= i <= n+1として総和をとる。
*/


const int MOD = 1e9 + 7;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  ll n, k;
  cin >> n >> k;

  ll ans = 0;
  for (ll i = k; i <= n+1; ++i) {
    ll l = i * (i-1) / 2;

    ll r = i * (2*n-i+1) / 2;

    ll add = r - l + 1;
    ans = (add + ans) % MOD;
  }

  cout << ans << "\n";
  return 0;
}